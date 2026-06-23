class myQueue {
  int* arr;
  int cap;
  int front;
  int rear;
  int size;
  
  public:
    myQueue(int n) {
        // Define Data Structures
        cap=n;
        arr=new int[cap];
        front=0;
        rear=-1;
        size=0;
    }

    bool isEmpty() {
        
        return size==0;
        
    }

    bool isFull() {
        return size==cap;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull())
        {
            cout<<"overflow";
            return ;
        }
        rear=(rear+1)%cap;
        arr[rear]=x;
        size++;
        return ;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty())
        {
            cout<<"underflow"<<endl;
            return;
        }
        size--;
        front=(front+1)%cap;
    }

    int getFront() {
        if(isEmpty()) return -1;
        int a=arr[front];
        // Returns the front element of the queue.
        return a;
    }

    int getRear() {
        if(isEmpty()) return -1;
        int a=arr[rear];
        return a;
        // Return the last element of queue
        
    }
};