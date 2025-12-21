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
