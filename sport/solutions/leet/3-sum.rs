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
use std::env;
use std::io::Write;
// use std::io::{self, BufReader, BufRead};
use std::io;
use std::iter::FromIterator;
use std::ops::{Add, AddAssign};
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

    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        // 3000C3은 범위를 넘어가므로 불가능.
        // 일단 아마 인덱싱을 이용하는 트릭은 반드시 필요할 듯 한데..
        // 두 수를 선택하면, 나머지 한 수는 있는지 없는지 인덱스로 찾기만 하면 되긴 한다.
        // 다만 그렇게 할 경우 중복을 어떻게 체크할 것인지가 문제다.
        // [-1, -1, 2]는 [-1, 2, -1]과 같은 것으로 처리.

        // 반대로 어떤 합을 만들 수 하나를 결정하면, 나머지 두 수로 그 합을 만든다고 생각할 수도 있다.
        // 그 경우 중복 처리에 좀 더 유리할 지도 모르겠다.
        // 그렇지만 결국 반대로 선택하는 경우를 어떻게 제외할 지 모르겠다.
        // 0을 선택하고 만드려면 0 세개,
        // 어떤 양수 하나를 선택하면, 0이 되려면 음수 두 개 or 음수 하나, 양수 하나를 선택해야 한다.
        // 일단 두 수를 선택해서 그 합을 계산해서, 그에 맞는 같은 값이 있는지 체크한다면?
        // 에라 모르겠다. 일단 그렇게 해 보자.

        // 역시 몇개 남았는지 추적 없이는 의미가 없다.
        // 수동으로 재귀로 선택 하면서, 개수 관리하면서, 만들어야 할 합에 해당하는 수가 남아있다면 성공
        // 그래도 이 방법이 될 거라고 생각은 드는 게, 3000C3이 아닌, 3000C2로 줄이기 때문에 충분히 가능은 하다.
        // 구현이 귀찮을 뿐..

        use std::collections::HashMap;
        use std::collections::HashSet;

        let mut sums: Vec<i32> = vec![];

        let mut map1: HashMap<i32, i32> = HashMap::from([]);
        let mut set1: HashSet<i32> =
            HashSet::from(nums.clone().into_iter().collect::<HashSet<i32>>());

        let mut ans: HashSet<Vec<i32>> = HashSet::new();
        let mut cnt = 0;

        for item in &nums {
            let vv = map1.entry(*item).or_insert(0);
            if *vv <= 2 {
                *vv += 1;
            }
        }

        // dbg!(&map1);

        let zeros = *map1.entry(0).or_insert(0);

        if zeros >= 3 {
            ans.insert(vec![0, 0, 0]);
        }

        for item1 in &set1 {
            *map1.get_mut(item1).unwrap() -= 1;

            for item2 in &set1 {
                if item2 < item1 {
                    continue;
                }

                // 값이 없으면 continue
                // 값이 있으면, 0보다 크면 1 빼고 진행,
                // 값이 있는데 0이면 continue

                let item2_cnt = map1.get_mut(&item2).unwrap();
                if *item2_cnt > 0 {
                    *item2_cnt -= 1;
                } else {
                    continue;
                };

                let target = -item1 + -item2;
                match map1.get(&target) {
                    Some(vv) => {
                        if *vv > 0 && target >= *item2 {
                            cnt += 1;
                            ans.insert(Vec::from([*item1, *item2, target]));
                        }
                    }
                    None => {
                        *map1.get_mut(item2).unwrap() += 1;
                        continue;
                    }
                };

                *map1.get_mut(item2).unwrap() += 1;
            }

            *map1.get_mut(item1).unwrap() += 1;
        }

        // dbg!(cnt);

        // dbg!(&ans);

        ans.into_iter().collect()
    }

    fn solve<R: io::BufRead, W: io::Write>(scan: &mut UnsafeScanner<R>, out: &mut W) {
        let nums = vec![0, 0, 0, 0, 0];
        let nums = vec![1, 2, -2, -1];
        let nums = vec![-1, 0, 1, 2, -1, -4];
        // 같은 수가 들어올 수도 있다.

        let ans = three_sum(nums);

        dbg!(ans);

        // hashset test

        // use std::collections::HashSet;

        // let mut set1 = HashSet::from([vec![1, 2, 3]]);

        // set1.insert(vec![1, 2, 3]);

        // set1.insert(vec![1, 2, 3]);

        // set1.insert(vec![3, 2, 1]);

        // dbg!(set1);
    }

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut out = io::BufWriter::new(stdout.lock());
    let mut scan = UnsafeScanner::new(stdin.lock());
    solve(&mut scan, &mut out);
}
