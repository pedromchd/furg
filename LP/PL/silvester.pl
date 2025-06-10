% Fatos
passaro(tweety).
peixe(goldie).
minhoca(molie).
gato(silvester).

% Regras de gosto
gosta(X, Y) :- passaro(X), minhoca(Y).       % Pássaros gostam de minhocas
gosta(X, Y) :- gato(X), peixe(Y).            % Gatos gostam de peixes
gosta(X, Y) :- gato(X), passaro(Y).          % Gatos gostam de pássaros
gosta(X, Y) :- amigo(X, Y).                  % Amigos gostam uns dos outros

% Regras de amizade
amigo(silvester, eu).
amigo(eu, silvester).

% Silvester come tudo que gosta (sem exceções)
come(silvester, X) :- gosta(silvester, X).

% Consulta para descobrir o que Silvester come:
?- come(silvester, X).