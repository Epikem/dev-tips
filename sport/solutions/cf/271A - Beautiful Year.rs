

use std::fs;
use std::env;
use std::io::{self, BufReader, BufRead};

#[allow(unused_macros)]
macro_rules! debug {
    ($e: expr, $DEBUG: ident) => {
        if $DEBUG {
            println!("{} = {}", stringify!($e), $e);
        }
    }
}

macro_rules! debug2 {
    ($e: expr) => {
        println!("{} = {}", stringify!($e), $e);
    }
}

fn get_debug_function(debug: bool) -> Box<dyn Fn(i32)> {
    if debug {
        Box::new(|x| debug2!(x))
    } else {
        Box::new(|_x| ())
    }
}

fn get_debug_mode(mode: &str) -> Option<String> {
    if mode == "stdin" {
        None
    } else {
        Some("input.txt".to_string())
    }
}

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

    // let input = env::args().nth(1);
    let reader: Box<dyn BufRead> = match get_debug_mode(&input) {
        None => Box::new(BufReader::new(io::stdin())),
        Some(filename) => Box::new(BufReader::new(fs::File::open(filename).unwrap()))
    };

    for line in reader.lines() {
        // debug!("{:?}", line, debgu);
        match line {
            Ok(num) => {
                let mystr = num.to_string();
                let mut ans = mystr.clone();

                loop {
                    let number = ans.parse::<i32>().unwrap() + 1;
                    ans = number.to_string();
                    if check_duplicate_digit(&ans) {
                        println!("{}", ans);
                        return;
                    }
                }
                
            },
            Err(err) => {
                dbg!(err);
                panic!("wha");
            }
        }
    }

}

fn check_duplicate_digit(num_str: &String) -> bool {
    let chars = num_str.chars();

    use std::collections::HashSet;
    
    let mut set = HashSet::new();
    set.extend(chars.clone());
    // let cnt = chars.count();
    let cnt = chars.count();
    cnt == set.len()
}