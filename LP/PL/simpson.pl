homem(abraham).
homem(clancy).
homem(herb).
homem(homer).
homem(bart).
homem(maridoSelma).
homem(ling).

mulher(mona).
mulher(jackie).
mulher(marge).
mulher(patty).
mulher(selma).
mulher(lisa).
mulher(maggie).


pai(abraham, herb).
pai(abraham, homer).
pai(clancy, marge).
pai(clancy, patty).
pai(clancy, selma).
pai(homer, bart).
pai(homer, lisa).
pai(homer, maggie).
pai(maridoSelma, ling).

mae(mona, herb).
mae(mona, homer).
mae(jackie, marge).
mae(jackie, patty).
mae(jackie, selma).
mae(marge, bart).
mae(marge, lisa).
mae(marge, maggie).
mae(selma, ling).


casado(abraham, mona).
casado(clancy, jackie).
casado(homer, marge).
casado(maridoSelma, selma).

filho(X, Y) :- pai(Y, X).
filho(X, Y) :- mae(Y, X).

irmao(X, Y) :- pai(Z, X), pai(Z, Y), X \= Y.
irmao(X, Y) :- mae(Z, X), mae(Z, Y), X \= Y.

tio(X, Y) :- irmao(X, Z), pai(Z, Y).
tia(X, Y) :- irmao(X, Z), mae(Z, Y).

primo(X, Y) :- pai(Z, X), pai(W, Y), irmao(Z, W).
primo(X, Y) :- mae(Z, X), mae(W, Y), irmao(Z, W).

avo(X, Y) :- pai(X, Z), pai(Z, Y).
avo(X, Y) :- pai(X, Z), mae(Z, Y).
avo(X, Y) :- mae(X, Z), pai(Z, Y).
avo(X, Y) :- mae(X, Z), mae(Z, Y).

% a. Quem são as mulheres da família?
mulher(X).

% b. Quem são seus tios e tias do Bart por parte de mãe?
tio(X, bart), pai(clancy, X).
tia(X, bart), mae(jackie, X).

% c. Quem são seus tios e tias do Bart por parte de pai?
tio(X, bart), pai(abraham, X).
tia(X, bart), mae(mona, X).

% d. Quem são seus tios e tias do Bart que se casaram com parentes seus?
(tio(X, bart); tia(X, bart)), casado(X, Y).
(tio(X, bart); tia(X, bart)), casado(Y, X).

% e. Quem são seus primos do Bart por parte de pai?
primo(X, bart), pai(abraham, Y), pai(Y, X).

% f. Quem são seus primos do Bart por parte de mãe?
primo(X, bart), mae(jackie, Y), mae(Y, X).