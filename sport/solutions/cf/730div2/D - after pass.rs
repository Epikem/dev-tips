#![allow(unused)]
// NYAN NYAN
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
// ░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
// ░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
// ░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
// ░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
// ░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
// ░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
// ░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░
// ░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
// ░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
// ░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
// ░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// CREDIT:
// read write module: https://github.com/EbTech/rust-algorithms
//! Generic utility for reading data from standard input, based on [voxl's
//! stdin wrapper](http://codeforces.com/contest/702/submission/19589375).

// use std::fs;
use std::io::Write;
use std::env;
// use std::io::{self, BufReader, BufRead};
use std::io;
use std::str;

/// Reads white-space separated tokens one at a time.
pub struct Scanner<R> {
    reader: R,
    buffer: Vec<String>,
}

impl<R: io::BufRead> Scanner<R> {
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            buffer: vec![],
        }
    }

    /// Use "turbofish" syntax token::<T>() to select data type of next token.
    ///
    /// # Panics
    ///
    /// Panics if there's an I/O error or if the token cannot be parsed as T.
    pub fn token<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            self.reader.read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

/// Same API as Scanner but nearly twice as fast, using horribly unsafe dark arts
/// **REQUIRES** Rust 1.34 or higher
pub struct UnsafeScanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: str::SplitAsciiWhitespace<'static>,
}

impl<R: io::BufRead> UnsafeScanner<R> {
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            buf_str: vec![],
            buf_iter: "".split_ascii_whitespace(),
        }
    }

    /// This function should be marked unsafe, but noone has time for that in a
    /// programming contest. Use at your own risk!
    pub fn token<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            self.buf_iter = unsafe {
                let slice = str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_ascii_whitespace())
            }
        }
    }
}

pub fn scanner_from_file(filename: &str) -> Scanner<io::BufReader<std::fs::File>> {
    let file = std::fs::File::open(filename).expect("Input file not found");
    Scanner::new(io::BufReader::new(file))
}

pub fn writer_to_file(filename: &str) -> io::BufWriter<std::fs::File> {
    let file = std::fs::File::create(filename).expect("Output file not found");
    io::BufWriter::new(file)
}

macro_rules! dbg2 {
    () => {
        eprintln!("[{}:{}]", file!(), line!());
    };
    ($val:expr) => {
        // Use of `match` here is intentional because it affects the lifetimes
        // of temporaries - https://stackoverflow.com/a/48732525/1063961
        match $val {
            tmp => {
                eprintln!("[{}:{}] {} = {:?}",
                    file!(), line!(), stringify!($val), &tmp);
                tmp
            }
        }
    };
    // Trailing comma with single argument is ignored
    ($val:expr,) => { dbg2!($val) };
    ($($val:expr),+ $(,)?) => {
        ($(dbg2!($val)),+,)
    };
}

macro_rules! debug {
    ($e: expr, $DEBUG: ident) => {
        if $DEBUG {
            println!("{} = {}", stringify!($e), $e);
        }
    }
}

fn main() {
    fn ri32<R: io::BufRead>(scan: &mut UnsafeScanner<R>) -> i32 {
        scan.token::<i32>()
    }

    fn rstr<R: io::BufRead>(scan: &mut UnsafeScanner<R>) -> String {
        scan.token::<String>()
    }

    fn ru32<R: io::BufRead>(scan: &mut UnsafeScanner<R>) -> u32 {
        scan.token::<u32>()
    }

    fn rusize<R: io::BufRead>(scan: &mut UnsafeScanner<R>) -> usize {
        scan.token::<usize>()
    }

    fn ri64<R: io::BufRead>(scan: &mut UnsafeScanner<R>) -> i64 {
        scan.token::<i64>()
    }

    fn rf64<R: io::BufRead>(scan: &mut UnsafeScanner<R>) -> f64 {
        scan.token::<f64>()
    }

    fn rline<R: io::BufRead>(scan: &mut UnsafeScanner<R>){
        // scan.reader.read_line(buf: &mut String)
    }

    // https://stackoverflow.com/questions/41447678/comparison-of-two-floats-in-rust-to-arbitrary-level-of-precision
    fn approx_equal (a:f64,b:f64,dp:u8) -> bool {
        let p:f64 = 10f64.powf(-(dp as f64));
    
        if (a-b).abs() < p {
            return true;
        } else {
            return false;
        }
    }

    fn from_base_vector(vector: &Vec<i32>, base: i32) -> i32 {
        let mut result = 0;
        
        for (i, item) in vector.iter().enumerate() {
            result = result + item * base.pow(i as u32);
        }

        result
    }

    fn to_base_vector(original: i32, base:i32) -> Vec<i32> {
        let mut vec = vec![];
        let mut ori = original;
        if ori == 0 {
            vec.push(0);
            return vec;
        }

        while ori > 0 {
            vec.push(ori % base);
            ori = ori / base;
        }
        
        return vec;
    }

    enum VectorOp {
        Add,
        Sub
    }

    fn vector_op(op: VectorOp, a: Vec<i32>, b: Vec<i32>, modv: i32) -> Vec<i32> {
        match op {
            VectorOp::Add => {
                return vector_xor(&a, &b, modv);
            },
            VectorOp::Sub => {
                return vector_sub_xor(&a, &b, modv);
            }
        }
    }

    fn vector_xor(a: &Vec<i32>, b: &Vec<i32>, modv: i32) -> Vec<i32> {
        let mut result = vec![];
        let alen = a.len();
        let blen = b.len();
        let len = std::cmp::max(alen, blen);
        
        for i in 0..len {
            let aval = if i < alen { a[i] } else { 0 };
            let bval = if i < blen { b[i] } else { 0 };
            result.push((aval + bval) % modv);
        }

        result
    }

    fn vector_sub_xor(a: &Vec<i32>, b: &Vec<i32>, modv: i32) -> Vec<i32> {
        let mut result = vec![];
        let alen = a.len();
        let blen = b.len();
        let len = std::cmp::max(alen, blen);
        
        for i in 0..len {
            let aval = if i < alen { a[i] } else { 0 };
            let bval = if i < blen { b[i] } else { 0 };
            // dbg2!(aval, bval, modv);
            result.push((aval - bval + modv) % modv);
        }

        result
    }

    fn solve<R: io::BufRead, W: io::Write>(scan: &mut UnsafeScanner<R>, out: &mut W) {
        let cases = ri32(scan);

        let mut vects = vec![vec![0];200005];
        
        for _case in 0..cases {
            let (n,k) = (rusize(scan), ri32(scan));
            let modv = k;
            let mut query = to_base_vector(0, modv);

            // let mut vects = vec![];
            for i in 0..n+2 {
                vects[i] = to_base_vector(i as i32, modv);
            }

            for i in 0..n {
                writeln!(out, "{}", from_base_vector(&query, modv));
                out.flush();
                if ri32(scan) == 1 { 
                    break; 
                }

                // let im1 = to_base_vector(i-1, modv);
                // let im2 = to_base_vector(i-2, modv);
                let im1 = &vects[i+1];
                let im2 = &vects[i];
                
                query = if i % 2 == 0 {
                    vector_sub_xor(&im2, &im1, modv)
                } else {
                    vector_sub_xor(&im1, &im2, modv)
                };
                
                // writeln!(out, "{:?} {:?} {:?} {:?} {:?} {:?}", im1, im2, &query, from_base_vector(&im1, modv), from_base_vector(&im2, modv), from_base_vector(&query, modv));
            }
        }
    }

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut out = io::BufWriter::new(stdout.lock());
    let mut scan = UnsafeScanner::new(stdin.lock());
    solve(&mut scan, &mut out);
}
