class Node {
    // Inicialización de valor y puntero
    constructor(data) {
        this.data = data;
        this.next = null;
    };
}

class LinkedList {
    // Inicialización de head, tail y length
    constructor() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    };

    // Insertar al principio O(1)
    insertAtBeginning(value) {
        let newNode = new Node(value);
        this.length++;

        // Verificar si this.head existe
        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
            return;
        }

        // Agregar al inicio
        newNode.next = this.head;
        this.head = newNode;
    };

    // Insertar al final O(1)
    insertAtEnd(value) {
        let newNode = new Node(value);
        this.length++;

        // Verificar si this.head existe
        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
            return;
        }

        // Agregar al final
        this.tail.next = newNode;
        this.tail = this.tail.next;
    }

    // Insertar en cierta posición O(n)
    insertAtPosition(pos, value) {
        // Verificar posición en rango
        if (pos < 0 || pos > this.length) {
            console.log("Out of range of the list")
            return;
        }

        // Insertar al principio
        if (pos === 0) {
            this.insertAtBeginning(value);
            return;
        }

        // Insertar al final
        if (pos === this.length) {
            this.insertAtEnd(value);
            return;
        }

        // Insertar dentro de la lista
        let newNode = new Node(value);
        let currPosition = 1
        let curr = this.head
        while (currPosition < pos) {
            curr = curr.next;
            currPosition++;
        }
        newNode.next = curr.next;
        curr.next = newNode;
    }

    // Elimina el primer nodo que contenga ese valor O(n)
    deleteValue(value) {
        // Caso en el que queremos eliminar el primer nodo
        if (this.head.data === value) {
            this.head = this.head.next;
            this.length--;
            return;
        }

        // Caso en el que no queremos eliminar el primer nodo
        let curr = this.head;
        while (curr.next) {
            let nxt = curr.next;
            if (nxt.data === value) {
                curr.next = nxt.next;
                this.length--;
                if (curr.next === null) {
                    this.tail = curr;
                }
                return;
            }
            curr = curr.next;
        }
