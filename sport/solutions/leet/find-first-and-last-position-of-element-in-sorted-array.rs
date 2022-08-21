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

use std::cmp::min;
use std::collections::HashMap;
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

    fn get_closer(ori: f64, target: f64) -> f64 {
        // if |target - ori| <= 0.5, don't move
        if (target - ori).abs() <= 0.5f64 {
            return ori;
        }
        // otherwise, move closer by one unit
        let plus_ori = ori + 1.0f64;
        let sub_ori = ori - 1.0f64;
        // return which of the two is closer to target
        if (target - plus_ori).abs() < (target - sub_ori).abs() {
            return plus_ori;
        } else {
            return sub_ori;
        }
    }

    // Input: nums = [5,7,7,8,8,10], target = 8
    // Output: [3,4]

    // Input: nums = [5,7,7,8,8,10], target = 6
    // Output: [-1,-1]

    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        // 이분 탐색을 두번 해서, 시작 인덱스와 끝 인덱스를 찾아서 반환한다.
        let mut start = 0;
        let mut end = nums.len();

        if (end == 0) {
            return vec! [-1, -1];
        }

        // 1.
        let mut le = 0;
        let mut ri = nums.len();
        let mut mid = (le + ri) / 2;
        while (le < ri) {
            // 일단 가운데를 찍어본다.
            mid = (le + ri) / 2;
            // 시작값은, 같은 값 중 최소
            // 가운데가 목표값보다 크다면?
            if (nums[mid] > target) {
                ri = mid;
            } else if (nums[mid] == target) {
                // 이 때는?
                ri = mid;
                // 왜 이렇게 생각하나?
                // 범위를 일단 왼쪽으로 줄이니 아마 가장 작은 값이 찾아지지 않을까..
            } else {
                le = mid + 1;
            }
        }

        // dbg!("first", le, mid, ri, nums[le], nums[mid], nums[ri]);
        start = le;
        le = 0;
        ri = nums.len();
        let mut mid2 = (le + ri) / 2;
        while (le < ri) {
            // 일단 가운데를 찍어본다.
            mid2 = (le + ri) / 2;
            // 시작값은, 같은 값 중 최소
            // 가운데가 목표값보다 크다면?
            if (nums[mid2] > target) {
                ri = mid2;
            } else if (nums[mid2] == target) {
                // 이 때는?
                le = mid2 + 1;
            } else {
                le = mid2 + 1;
            }
        }

        if (le > 0) {
            end = le - 1;
        } else {
            end = 0;
        }

        // dbg!("second", le, mid2, ri, nums[le], nums[mid2], nums[ri], end);
        dbg!("second", le, mid2, ri, end);

        if (nums[end] == target) {
            return vec! [start as i32, end as i32];
        }

        return vec! [-1, -1];
    }

    fn solve<R: io::BufRead, W: io::Write>(scan: &mut UnsafeScanner<R>, out: &mut W) {
        // read 1 integer
        let i1 = ri32(scan);

        // print
        dbg!(i1, true);

        // // Input: nums = [5,7,7,8,8,10], target = 8
        // let nums = vec! [5,7,7,8,8,8,8,10];
        // let target = 8;

        // Input: nums = [5,7,7,8,8,10], target = 6
        // Output: [-1,-1]
        let nums = vec! [0, 0];
        let target = 0;

        let ans = search_range(nums, target);

        dbg!(ans);
    }

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut out = io::BufWriter::new(stdout.lock());
    let mut scan = UnsafeScanner::new(stdin.lock());
    solve(&mut scan, &mut out);
}

