# https://leetcode.com/problems/implement-queue-using-stacks/

class Stack:
    def __init__(self):
        self.internal = []
    def push(self, x):
        self.internal.append(x)
    def pop(self):
        return self.internal.pop()
    def is_empty(self):
        return len(self.internal) == 0



#s1 = Stack()
#s2 = Stack()
#s1.push(1)
#s1.push(2)
#s1.push(3)
#print(s1.pop())
#print(s1.pop())
#print(s1.pop())


class MyQueue:

    def __init__(self):
        self.s1 = Stack()
        self.s2 = Stack()
        
    def push(self, x: int) -> None:
        self.s1.push(x)

    def pop(self) -> int:

        while self.s1.is_empty() == False:
            item = self.s1.pop()
            self.s2.push(item)
        
        resulting_element = self.s2.pop()

        while self.s2.is_empty() == False:
            item = self.s2.pop()
            self.s1.push(item)
        
        return resulting_element

    def peek(self) -> int:
        while self.s1.is_empty() == False:
            item = self.s1.pop()
            self.s2.push(item)
        
        resulting_element = self.s2.pop()
        
        self.s2.push(resulting_element) # push back in

        while self.s2.is_empty() == False:
            item = self.s2.pop()
            self.s1.push(item)
                
        return resulting_element

    def empty(self) -> bool:
        return self.s1.is_empty()
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
