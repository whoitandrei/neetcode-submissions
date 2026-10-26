struct MyCircularQueue {
    buf: Vec<i32>,
    len: usize,
    head: usize,
}

impl MyCircularQueue {
    pub fn new(k: i32) -> Self {
        MyCircularQueue {
            buf: vec![0; k as usize],
            head: 0,
            len: 0,
        }
    }

    pub fn en_queue(&mut self, value: i32) -> bool {
        if self.len == self.buf.len() {
            return false;
        }   
        let k = self.buf.len();
        let idx = (self.head + self.len) % k;
        self.buf[idx] = value;
        self.len += 1;
        true
    }

    pub fn de_queue(&mut self) -> bool {
        if self.len == 0 {
            return false;
        }
        self.head = (self.head + 1) % self.buf.len();
        self.len -= 1;  
        true
    }

    pub fn front(&self) -> i32 {
        if self.len == 0 {
            return -1;
        }
        self.buf[self.head]
    }

    pub fn rear(&self) -> i32 {
        if self.len == 0 {
            return -1;
        }
        self.buf[(self.head + self.len - 1) % self.buf.len()]
    }

    pub fn is_empty(&self) -> bool {
        self.len == 0
    }

    pub fn is_full(&self) -> bool {
        self.len == self.buf.len()
    }
}
