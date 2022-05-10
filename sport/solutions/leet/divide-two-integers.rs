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

    fn get_sign(num: i32) -> i32 {
        if num < 0 {
            return -1;
        } else if num > 0 {
            return 1;
        } else {
            return 0;
        }
    }

    pub fn divide_impl(dividend: i32, divisor: i32) -> i32 {
        // 1. 부호가 같은지 다른지 체크
        // 2. 부호가 같다면 빼서, 다르다면 더해가면서 나누기
        // 3. 몫이 범위 초과할 경우 범위 제한하기
        // 4. 몫은 최종 부호 유지하면서 계산
        let dividend_sign = get_sign(dividend);
        let divisor_sign = get_sign(divisor);
        let quotient_sign = dividend_sign != divisor_sign;

        let mut left_dividend = dividend;
        let mut quotient: i32 = 0;
        let mut ori_dividend_sign = dividend_sign;
        let mut cur_dividend_sign = dividend_sign;

        // 부호를 뒤집지 못하는 게 상당히 귀찮게 하는데,
        // 큰 수에 대한 엣지 케이스만 처리하면 부호를 뒤집어도 되게 된다.
        // 그것은 dividend가 음수 최소 수, divisor가 -1인 경우 하나 뿐이다
        // 아니다. 그래도 dividend가 음수 최소 수, divisor가 다른 수일 때 괜찮을 지 모른다.

        if divisor == std::i32::MIN {
            if dividend == std::i32::MIN {
                return 1;
            } else if dividend_sign == -1 && dividend > divisor {
                return 0;
            } else if dividend_sign == 1 && -dividend > divisor {
                return 0;
            }
            return -divide_impl(dividend, -(divisor + 1));
        } else if divisor_sign == -1 {
            let res = divide_impl(dividend, -divisor);
            if res == std::i32::MIN {
                return std::i32::MAX;
            } else {
                return -res;
            }
        }

        if dividend == std::i32::MIN {
            if divisor == -1 {
                return std::i32::MAX;
            } else if divisor == 1 {
                return dividend;
            } else {
                if divisor_sign == -1 && dividend < divisor {
                    return divide_impl(-(dividend-divisor), -divisor) + 1;
                } else if divisor_sign == 1 && dividend < -divisor {
                    return -divide_impl(-(dividend+divisor), divisor) - 1;
                } else {
                    dbg!("ERROR: dividend = {}, divisor = {}", dividend, divisor);
                    return 0;
                }
            }
        } else if dividend_sign == -1 {
            return -divide_impl(-dividend, divisor);
        }

        while left_dividend >= divisor {
            left_dividend -= divisor;
            quotient += 1;
        }

        return quotient;
    }

    fn solve<R: io::BufRead, W: io::Write>(scan: &mut UnsafeScanner<R>, out: &mut W) {
        // case 1
        // let (dividend, divisor) = (10, 3);
        let (dividend, divisor) = (-10, -3);
        // let (dividend, divisor) = (1, 1);
        let (dividend, divisor) = (-2147483648, 2);
        let (dividend, divisor) = (-2147483648, -1);
        let (dividend, divisor) = (2147483647, -2147483648);

        let expected = 3;

        let output = divide_impl(dividend, divisor);

        dbg!(output, expected);
    }

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut out = io::BufWriter::new(stdout.lock());
    let mut scan = UnsafeScanner::new(stdin.lock());
    solve(&mut scan, &mut out);
}

