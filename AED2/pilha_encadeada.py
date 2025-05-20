# pilha_encadeada.py
# Assuming Nodo class is defined in nodo.py or within this file
# from nodo import Nodo # if in a separate file

class Nodo:
    def __init__(self, dado=None):
        self.info = dado
        self.prox = None

class PilhaEncadeada:
    def __init__(self):
        self.topo = None

    def vazia(self):
        return self.topo is None

    def empilha(self, dado):
        novo = Nodo(dado)
        if not self.vazia():
            novo.prox = self.topo
        self.topo = novo
        return True

    def desempilha(self):
        if not self.vazia():
            dado = self.topo.info
            self.topo = self.topo.prox
            return dado
        else:
            print("Pilha vazia! Não é possível desempilhar.")
            return None

    def consulta_topo(self):
        if not self.vazia():
            return self.topo.info
        else:
            print("Pilha vazia! Não há elemento no topo.")
            return None

    def destruir(self):
        while (not self.vazia()):
            self.desempilha() # Implicitly calls desempilha, which updates self.topo
        print("Pilha destruída.")

    def __str__(self):
        if self.vazia():
            return "Pilha vazia."
        current = self.topo
        elements = []
        while current:
            elements.append(str(current.info))
            current = current.prox
        return "Pilha: [" + ", ".join(elements) + "]"

    # Exercise 1: Invert the stack
    def inverter_pilha(self):
        if self.vazia():
            return

        # Use a temporary list to store elements in reversed order
        temp_list = []
        while not self.vazia():
            temp_list.append(self.desempilha())

        # Push elements back from the temporary list
        for item in temp_list:
            self.empilha(item)

    # Exercise 3: Return the smallest element without losing data
    def menor_elemento(self):
        if self.vazia():
            print("Pilha vazia. Não há menor elemento.")
            return None

        # Create a temporary stack to preserve the original stack
        temp_stack = PilhaEncadeada()
        menor = self.desempilha()
        temp_stack.empilha(menor)

        while not self.vazia():
            current_element = self.desempilha()
            temp_stack.empilha(current_element)
            if current_element < menor:
                menor = current_element

        # Restore the original stack
        while not temp_stack.vazia():
            self.empilha(temp_stack.desempilha())

        return menor
