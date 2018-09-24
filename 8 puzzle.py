s = dict()
dxy = [[0, 1], [0, -1], [1, 0], [-1, 0]]

class Stack:
    def __init__(self):
        self.str = []
    def push(self, ob):
        self.str.append(ob)
    def pop(self):
        self.str.pop()
    def top(self):
        return self.str[len(self.str) - 1]
    def empty(self):
        return len(self.str) == 0

stk = Stack()

def cor(ls):
    for i in range(3):
        for j in range(3):
            if(ls[i][j] == 0):
                return [i, j]

def bfs(initial, goal,moves):
    from queue  import Queue
    q = Queue()
    q.put(initial)
    while q.empty() == False:
        u = q.get()
        if(u == goal or moves>483843):
            print(u)
            return u,moves
        x, y = map(int, cor(u))
        for i in range(4):
            vx = x + dxy[i][0]
            vy = y + dxy[i][1]
            if(vx >= 0 and vx < 3 and vy >= 0 and vy < 3):
                import copy
                ls = copy.deepcopy(u)
                ls[x][y], ls[vx][vy] = ls[vx][vy], ls[x][y]
                moves=moves+1
                print(moves)
                if(str(ls) not in s.keys()):
                    q.put(ls)
                    s.update({str(ls) : u})
                del ls






start = [[1, 2, 3],
         [5, 8, 7],
         [6, 0, 4]]

end = [[1, 2, 3],
       [4, 5, 0],
       [7, 8, 6]]

now,moves = bfs(start, end,0)
if(moves>483843):
    now, moves = bfs(start, end, 0)

def display(ls):
    for el in ls:
        print(el)

    print('\n')

stk.push(now)

while(s[str(now)] != start):
    now = s[str(now)]
    stk.push(now)

stk.push(start)

while(stk.empty() == False):
    display(stk.top())
    stk.pop()