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
        while not self.vazia():
            self.desempilha()
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

    def inverter_pilha(self):
        if self.vazia():
            return

        temp_list = []
        while not self.vazia():
            temp_list.append(self.desempilha())

        for item in temp_list:
            self.empilha(item)

    def menor_elemento(self):
        if self.vazia():
            print("Pilha vazia. Não há menor elemento.")
            return None

        temp_stack = PilhaEncadeada()

        menor = self.desempilha()
        temp_stack.empilha(menor)

        while not self.vazia():
            current_element = self.desempilha()
            temp_stack.empilha(current_element)
            if current_element < menor:
                menor = current_element

        while not temp_stack.vazia():
            self.empilha(temp_stack.desempilha())

        return menor
