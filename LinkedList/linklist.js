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

        // Si no se encuentra el valor
        console.log("Couldn't find the value on the linked list");

    }

    // Devolver true si el valor está en la lista, false si no O(n)
    search(value) {
        let curr = this.head;

        // Buscar el valor
        while (curr) {
            // Retornar verdadero si se encuentra
            if (curr.data === value) {
                return true
            }
            curr = curr.next;
        }

        // Retornar falso si no se encuentra
        return false;
    }

    // Mostrar todos los elementos en orden O(n)
    display() {
        let curr = this.head;

        // Imprimir todos los nodos
        while (curr) {
            console.log(curr);
            curr = curr.next;
        }
    }
}


// === TESTS ===
let myList = new LinkedList();

console.log('== Insert at end ==');
myList.insertAtEnd(100);
myList.insertAtEnd(200);
myList.insertAtEnd(300);
myList.display();

console.log('\n== Insert at beginning ==');
myList.insertAtBeginning(50);
myList.display();

console.log('\n== Insert at position 2 (should be 150) ==');
myList.insertAtPosition(2, 150);
myList.display();

console.log('\n== Search for existing and non-existing values ==');
console.log('Search 100:', myList.search(100)); // true
console.log('Search 999:', myList.search(999)); // false

console.log('\n== Delete value 200 (middle) ==');
myList.deleteValue(200);
myList.display();

console.log('\n== Delete value 50 (head) ==');
myList.deleteValue(50);
myList.display();

console.log('\n== Delete value 300 (tail) ==');
myList.deleteValue(300);
myList.display();

console.log('\n== Try to delete non-existing value 999 ==');
myList.deleteValue(999);
myList.display();