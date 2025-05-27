if (sim_call_type==sim.syscb_init) then 
    steer_handle= sim.getObjectHandle('steer_joint') -- Pega o volante
    motor_handle= sim.getObjectHandle('motor_joint') -- Pega o motor
    fl_brake_handle= sim.getObjectHandle('fl_brake_joint') -- Freio dianteiro esquerdo
    fr_brake_handle= sim.getObjectHandle('fr_brake_joint') -- Freio dianteiro direito
    bl_brake_handle= sim.getObjectHandle('bl_brake_joint') -- Freio traseiro esquerdo
    br_brake_handle= sim.getObjectHandle('br_brake_joint') -- Freio traseiro direito

    --wheel radius:         0.09
    --wheel base:             0.6
    --wheel track:             0.35
    --maximum steering rate:     70 deg/sec

    --the maximum steer angle 30 degree
    max_steer_angle=0.5235987 -- Valor em radianos equivalente a 30 graus

    --the maximum torque of the motor
    motor_torque=60 -- Força máxima que o motor pode aplicar

    dVel=1 -- Passo de velocidade ao apertar tecla
    dSteer=0.1 -- Passo de virada ao apertar tecla

    --input steer
    steer_angle=0 -- Começa com volante reto

    --input velocity
    motor_velocity=dVel*10 -- Começa com velocidade padrão

    --input brake
    brake_force=0 -- Começa sem freio ativado
end 

if (sim_call_type==sim.syscb_cleanup) then 
    -- Executado ao finalizar o código
end 

if (sim_call_type==sim.syscb_actuation) then 
    --current steer pos
    steer_pos=sim.getJointPosition(steer_handle); -- Pega a posição atual do volante

    --current angular velocity of back left wheel
    bl_wheel_velocity=sim.getObjectFloatParameter(bl_brake_handle,2012) -- Velocidade da roda traseira esquerda

    --current angular velocity of back right wheel
    br_wheel_velocity=sim.getObjectFloatParameter(br_brake_handle,2012) -- Velocidade da roda traseira direita

    --average angular velocity of the back wheels
    rear_wheel_velocity=(bl_wheel_velocity+br_wheel_velocity)/2 -- Média das velocidades das rodas traseiras

    --linear velocity
    linear_velocity=rear_wheel_velocity*0.09 -- Calcula velocidade em m/s (multiplica pelo raio da roda)

    -- Read the keyboard messages (make sure the focus is on the main window, scene view):
    message,auxiliaryData=sim.getSimulatorMessage() -- Lê entrada do teclado
    while message~=-1 do -- Enquanto houver teclas pressionadas
        if (message==sim.message_keypress) then
            Msg="Tecla: "
            Msg=Msg..auxiliaryData[1] -- Mostra o código da tecla apertada
            sim.addStatusbarMessage(Msg) -- Escreve no status da simulação

            if (auxiliaryData[1]==2007) then -- Tecla para cima
                -- up key
                if (motor_velocity<dVel*9.99) then -- Se a velocidade for menor que o máximo
                    motor_velocity=motor_velocity+dVel -- Aumenta a velocidade
                end
            end
            if (auxiliaryData[1]==2008) then -- Tecla para baixo
                -- down key
                if (motor_velocity>-dVel*1.99) then -- Se a velocidade for maior que o mínimo
                    motor_velocity=motor_velocity-dVel -- Diminui a velocidade ou anda pra trás
                else
                    --    brake_force=100
                end
            end
            if (auxiliaryData[1]==2009) then -- Tecla para esquerda
                -- left key
                if (steer_angle<dSteer*4.99) then -- Se o volante não estiver virado ao máximo
                    steer_angle=steer_angle+dSteer -- Vira o volante para a esquerda
                end
            end
            if (auxiliaryData[1]==2010) then -- Tecla para direita
                -- right key
                if (steer_angle>-dSteer*4.99) then -- Se o volante não estiver virado ao máximo
                    steer_angle=steer_angle-dSteer -- Vira o volante para a direita
                end
            end
            if (auxiliaryData[1]==115) then -- Tecla 's'
                -- s key
                motor_velocity=0.0 -- Para o motor (zera a velocidade)
            end
        end
        message,auxiliaryData=sim.getSimulatorMessage() -- Lê a próxima tecla, se tiver
    end

    if (math.abs(motor_velocity)<dVel*0.1) then
        brake_force=100 -- Se estiver quase parado, ativa o freio
    else
        brake_force=0 -- Caso contrário, não freia
    end

    --set maximum steer angle
    if (steer_angle> max_steer_angle) then -- Se o volante estiver virado demais
        steer_angle=max_steer_angle -- Limita o valor do volante
    end
    if (steer_angle< -max_steer_angle) then -- Se o volante estiver virado demais para o outro lado
        steer_angle= -max_steer_angle -- Limita pro outro lado também
    end
    sim.setJointTargetPosition(steer_handle, steer_angle) -- Aplica o valor do volante

    --brake and motor can not be applied at the same time
    if(brake_force>0) then -- Se o freio estiver ativo
        sim.setJointForce(motor_handle, 0) -- Zera a força do motor se estiver freando
    else
        sim.setJointForce(motor_handle, motor_torque) -- Aplica força do motor
        sim.setJointTargetVelocity(motor_handle, motor_velocity) -- Define a velocidade do motor
    end

    sim.setJointForce(fr_brake_handle, brake_force) -- Aplica freio na frente direita
    sim.setJointForce(fl_brake_handle, brake_force) -- Aplica freio na frente esquerda
    sim.setJointForce(bl_brake_handle, brake_force) -- Aplica freio atrás esquerda
    sim.setJointForce(br_brake_handle, brake_force) -- Aplica freio atrás direita
end
