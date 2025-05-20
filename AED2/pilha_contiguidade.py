# pilha_contiguidade.py
class PilhaContiguidade:
    def __init__(self, tamanho):
        self.vetor = [None] * tamanho
        self.lim = tamanho - 1
        self.base = 0
        self.topo = self.base - 1  # Indicates an empty stack

    def vazia(self):
        return self.topo < self.base

    def empilha(self, dado):
        if (self.topo < self.lim):
            self.topo += 1
            self.vetor[self.topo] = dado
            return True
        else:
            print("Pilha cheia! Não é possível empilhar.")
            return False

    def desempilha(self):
        if (self.topo >= self.base):
            dado = self.vetor[self.topo]
            self.topo -= 1
            return dado
        else:
            print("Pilha vazia! Não é possível desempilhar.")
            return None

    def consulta_topo(self):
        if self.topo >= self.base:
            return self.vetor[self.topo]
        else:
            print("Pilha vazia! Não há elemento no topo.")
            return None

    def destruir(self):
        self.topo = self.base - 1
        print("Pilha destruída.")

    def __str__(self):
        if self.vazia():
            return "Pilha vazia."
        elements = [str(self.vetor[i]) for i in range(self.base, self.topo + 1)]
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
        temp_stack = PilhaContiguidade(self.lim + 1)
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
