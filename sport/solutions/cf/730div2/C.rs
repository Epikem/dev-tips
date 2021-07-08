//! Generic utility for reading data from standard input, based on [voxl's
//! stdin wrapper](http://codeforces.com/contest/702/submission/19589375).

// use std::fs;
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

#[cfg(test)]
mod test {
    use super::*;

    fn solve<R: io::BufRead, W: io::Write>(scan: &mut Scanner<R>, out: &mut W) {
        let x = scan.token::<i32>();
        let y = scan.token::<i32>();
        writeln!(out, "{} - {} = {}", x, y, x - y).ok();
    }

    fn unsafe_solve<R: io::BufRead, W: io::Write>(scan: &mut UnsafeScanner<R>, out: &mut W) {
        let x = scan.token::<i32>();
        let y = scan.token::<i32>();
        writeln!(out, "{} - {} = {}", x, y, x - y).ok();
    }

    #[test]
    fn test_in_memory_io() {
        let input: &[u8] = b"50 8";
        let mut scan = Scanner::new(input);
        let mut out = vec![];

        solve(&mut scan, &mut out);
        assert_eq!(out, b"50 - 8 = 42\n");
    }

    #[test]
    fn test_in_memory_unsafe() {
        let input: &[u8] = b"50 8";
        let mut scan = UnsafeScanner::new(input);
        let mut out = vec![];

        unsafe_solve(&mut scan, &mut out);
        assert_eq!(out, b"50 - 8 = 42\n");
    }

    #[test]
    fn test_compile_stdio() {
        let (stdin, stdout) = (io::stdin(), io::stdout());
        let mut scan = Scanner::new(stdin.lock());
        let mut out = io::BufWriter::new(stdout.lock());

        if false {
            solve(&mut scan, &mut out);
        }
    }

    #[test]
    #[should_panic(expected = "Input file not found")]
    fn test_panic_file() {
        let mut scan = scanner_from_file("input_file.txt");
        let mut out = writer_to_file("output_file.txt");

        solve(&mut scan, &mut out);
    }
}


#[allow(unused_macros)]
macro_rules! debug {
    ($e: expr, $DEBUG: ident) => {
        if $DEBUG {
            println!("{} = {}", stringify!($e), $e);
        }
    }
}

// fn get_debug_mode(mode: &str) -> Option<String> {
//     if mode == "stdin" {
//         None
//     } else {
//         Some("input.txt".to_string())
//     }
// }

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut debug = false;
    let mut input = "stdin";
    for arg in args.iter() {
        if arg.to_lowercase() == "debug" {
            debug = true;
        }
        if arg.to_lowercase() == "file" {
            // use file input when testing
            input = "input.txt";
        }
    }

    debug!("DEBUG print", debug);

    // // let input = env::args().nth(1);
    // let reader: Box<dyn BufRead> = match get_debug_mode(&input) {
    //     None => Box::new(BufReader::new(io::stdin())),
    //     Some(filename) => Box::new(BufReader::new(fs::File::open(filename).unwrap()))
    // };
    
    // let mut lines = reader.lines();

    
    // let cases = lines.next();
    #[allow(unused)]
    fn ri32<R: io::BufRead>(scan: &mut Scanner<R>) -> i32 {
        scan.token::<i32>()
    }

    #[allow(unused)]
    fn rstr<R: io::BufRead>(scan: &mut Scanner<R>) -> String {
        scan.token::<String>()
    }

    #[allow(unused)]
    fn ru32<R: io::BufRead>(scan: &mut Scanner<R>) -> u32 {
        scan.token::<u32>()
    }

    #[allow(unused)]
    fn ri64<R: io::BufRead>(scan: &mut Scanner<R>) -> i64 {
        scan.token::<i64>()
    }

    #[allow(unused)]
    fn rf64<R: io::BufRead>(scan: &mut Scanner<R>) -> f64 {
        scan.token::<f64>()
    }

    #[allow(unused)]
    fn rline<R: io::BufRead>(scan: &mut Scanner<R>){
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

    // 현재 상태로부터 예상 시행수를 구한다.
    fn dfs(a:f64, b:f64, c:f64, v:f64, n:i32) -> f64 {
        if approx_equal(a, 0.0, 5) && approx_equal(b, 0.0, 5) {
            return n as f64;
        }
        let mut sum_prob = 0.0;
        // a 고른 경우:
        if !approx_equal(a, 0.0, 5) {
            if a < v {
                if !approx_equal(b, 0.0, 5) {
                    // b가 0이 아님
                    sum_prob += a * dfs(0.0, b+a/2.0, c+a/2.0, v, n+1);
                } else {
                    // b가 0
                    sum_prob += a * dfs(0.0, 0.0, c+a, v, n+1);
                }
            } else {
                if !approx_equal(b, 0.0, 5) {
                    // b가 0이 아님
                    sum_prob += a * dfs(a-v, b+v/2.0, c+v/2.0, v, n+1);
                } else {
                    // b가 0
                    sum_prob += a * dfs(a-v, 0.0, c+v, v, n+1);
                }
            }
        }

        // b 고른 경우:
        if !approx_equal(b, 0.0, 5) {
            if b < v {
                if !approx_equal(a, 0.0, 5) {
                    // a가 0이 아님
                    sum_prob += b * dfs(a+b/2.0, 0.0, c+b/2.0, v, n+1);
                } else {
                    // a가 0
                    sum_prob += b * dfs(0.0, 0.0, c+b, v, n+1);
                }
            } else {
                if !approx_equal(a, 0.0, 5) {
                    // a가 0이 아님
                    sum_prob += b * dfs(a+v/2.0, b-v, c+v/2.0, v, n+1);
                } else {
                    // a가 0
                    sum_prob += b * dfs(0.0, b-v, c+v, v, n+1);
                }
            }
        }

        // p 고른 경우
        sum_prob += c*(n as f64);
        
        return sum_prob;
    }

    fn solve<R: io::BufRead, W: io::Write>(scan: &mut Scanner<R>, out: &mut W) {
        let cases = ri32(scan);
        
        for _case in 0..cases {
            let (c,m,p,v) = (rf64(scan), rf64(scan), rf64(scan), rf64(scan));

            // writeln!(out, "{} {} {} {}", c,m,p,v);
            let sum = dfs(c,m,p,v,1);

            writeln!(out, "{:.8}", sum);
        }
    }

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut out = io::BufWriter::new(stdout.lock());
    if input == "stdin" {
        let mut scan = Scanner::new(stdin.lock());
        solve(&mut scan, &mut out);
    } else {
        solve(&mut scanner_from_file("input.txt"), &mut out);
    }
}
