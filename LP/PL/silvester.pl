passaro(tweety).
peixe(goldie).
minhoca(molie).
gato(silvester).

gosta(X, Y) :- passaro(X), minhoca(Y).
gosta(X, Y) :- gato(X), peixe(Y).
gosta(X, Y) :- gato(X), passaro(Y).

amigo(silvester, eu).
amigo(eu, silvester).
gosta(X, Y) :- amigo(X, Y).

come(silvester, X) :- gosta(silvester, X).

% Consulta para descobrir o que Silvester come:
come(silvester, X).