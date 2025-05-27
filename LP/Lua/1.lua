function sysCall_init() 
    local robot=sim.getObject('.') -- Pega o próprio robô
    local obstacles=sim.createCollection(0) -- Cria uma coleção para obstáculos
    sim.addItemToCollection(obstacles,sim.handle_all,-1,0) -- Adiciona todos os objetos da cena nessa coleção
    sim.addItemToCollection(obstacles,sim.handle_tree,robot,1) -- Remove o robô da própria coleção, pois ele não é um obstáculo

    usensors={} -- Cria uma lista para guardar os sensores ultrassônicos
    for i=1,16,1 do -- Passa por todos os 16 sensores
        usensors[i]=sim.getObject("./ultrasonicSensor",{index=i-1}) -- Pega o sensor de índice i-1
        sim.setObjectInt32Param(usensors[i],sim.proxintparam_entity_to_detect,obstacles) -- Configura o sensor para detectar só os obstáculos
    end

    motorLeft=sim.getObject("./leftMotor") -- Pega o motor da roda esquerda
    motorRight=sim.getObject("./rightMotor") -- Pega o motor da roda direita
    noDetectionDist=0.5 -- Distância máxima para ainda considerar detecção
    maxDetectionDist=0.2 -- Distância a partir da qual o sensor ativa a resposta
    detect={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} -- Lista com os valores de detecção dos sensores
    braitenbergL={-0.2,-0.4,-0.6,-0.8,-1,-1.2,-1.4,-1.6, 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0} -- Pesos que os sensores aplicam à roda esquerda
    braitenbergR={-1.6,-1.4,-1.2,-1,-0.8,-0.6,-0.4,-0.2, 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0} -- Pesos que os sensores aplicam à roda direita
    v0=2 -- Velocidade base
end
-- This is a very simple EXAMPLE navigation program, which avoids obstacles using the Braitenberg algorithm


function sysCall_cleanup() 
    -- Executado ao encerrar o script
end 

function sysCall_actuation() 
    for i=1,16,1 do -- Verifica os 16 sensores
        res,dist=sim.readProximitySensor(usensors[i]) -- Lê se o sensor detectou algo e qual a distância
        if (res>0) and (dist<noDetectionDist) then -- Se o sensor detectou algo dentro da distância
            if (dist<maxDetectionDist) then -- Se estiver muito perto
                dist=maxDetectionDist -- Corrige o valor mínimo
            end
            detect[i]=1-((dist-maxDetectionDist)/(noDetectionDist-maxDetectionDist)) -- Calcula o quanto o sensor está vendo (0 a 1)
        else
            detect[i]=0 -- Se não viu nada, zera
        end
    end

    vLeft=v0 -- Começa com velocidade padrão na esquerda
    vRight=v0 -- Começa com velocidade padrão na direita

    for i=1,16,1 do -- Para cada sensor
        vLeft=vLeft+braitenbergL[i]*detect[i] -- Aplica o peso na roda esquerda
        vRight=vRight+braitenbergR[i]*detect[i] -- Aplica o peso na roda direita
    end

    sim.setJointTargetVelocity(motorLeft,vLeft) -- Aplica a velocidade na roda esquerda
    sim.setJointTargetVelocity(motorRight,vRight) -- Aplica a velocidade na roda direita
end 
