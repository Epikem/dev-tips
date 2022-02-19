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
use std::convert::TryInto;
// use std::fs;
use std::env;
use std::io::Write;
// use std::io::{self, BufReader, BufRead};
use std::io;
use std::ops::Index;
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
    };
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

    fn rline<R: io::BufRead>(scan: &mut UnsafeScanner<R>) {
        // scan.reader.read_line(buf: &mut String)
    }

    // https://stackoverflow.com/questions/41447678/comparison-of-two-floats-in-rust-to-arbitrary-level-of-precision
    fn approx_equal(a: f64, b: f64, dp: u8) -> bool {
        let p: f64 = 10f64.powf(-(dp as f64));

        if (a - b).abs() < p {
            return true;
        } else {
            return false;
        }
    }

    fn get_digits(num: i32) -> impl Iterator<Item = u32> {
        num.to_string()
            .chars()
            .map(|d| d.to_digit(10).unwrap())
            .collect::<Vec<_>>()
            .into_iter()
    }
    // 1.Read in and ignore any leading whitespace.
    // 2.Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
    // 3.Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
    // 4.Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
    // 5.If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
    // 6.Return the integer as the final result.
    pub fn my_atoi(s: String) -> i32 {
        // 1. lead space remove
        let chs = s.chars();
        let mut iter = chs.into_iter();
        let mut sign: i64 = 1;
        let mut in_num = false;
        let mut value: i64 = 0;
        let mut num_len = 0;
        let mut ans: i32 = 0;
        let mut clamp = false;

        for (idx, ch) in iter.enumerate() {
            if (in_num) {
                if (!"0123456789".contains(ch)) {
                    // end of number part. ignore rest
                    in_num = false;
                    break;
                } else {
                    // add the number and multiply 10
                    num_len += 1;
                    if value > (i32::MAX) as i64 {
                        value = i64::MAX;
                        break;
                    }
                    value *= 10;
                    value += ch.to_digit(10).unwrap() as i64;
                }
            }
            // 1. ignore spaces
            if (!in_num && ch != ' ') {
                in_num = true;
                // sign = if ch == '-' { -1 } else { 1 };
                // ignore leading zeros
                // what if 0~9?
                if ch == '-' {
                    sign = -1;
                } else if ch == '+' {
                    sign = 1;
                } else if ("123456789".contains(ch)) {
                    value += ch.to_digit(10).unwrap() as i64;
                    num_len += 1;
                } else if ('0' != ch) {
                    dbg!("asdasd");
                    return 0;
                }
            }
        }

        let mut ans = 0;
        // dbg!((value, sign));
        if (value > i32::MAX as i64) {
            ans = if (sign > 0) { i32::MAX } else { i32::MIN };
        } else {
            ans = (value * sign) as i32;
        }
        // dbg!(ans);
        ans
    }

    fn solve<R: io::BufRead, W: io::Write>(scan: &mut UnsafeScanner<R>, out: &mut W) {
        use std::collections::VecDeque;
        // let ins = "    -42".to_string();
        let ins = rstr(scan);
        // let ins = ".1".to_string();
        let res = my_atoi(ins);
        // let res = my_atoi("   +42.  ");
        dbg!(res);
        writeln!(out, "{}", res);
    }

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut out = io::BufWriter::new(stdout.lock());
    let mut scan = UnsafeScanner::new(stdin.lock());
    solve(&mut scan, &mut out);
}
