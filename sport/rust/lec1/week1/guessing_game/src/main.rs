extern crate rand;

use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {
    println!("Guess the number");
    let secret_number = rand::thread_rng().gen_range(1..101);
    // println!("answer: {}", secret_number);
    loop {
        println!("Please input your guess");
        
        let mut guess = String::new();
        
        io::stdin().read_line(&mut guess)
            .expect("failed to read line");
        
        // let guess :u32 = guess.trim().parse()
        //     .expect("pls type number!");

        let guess:u32=match guess.trim().parse() {
            Ok(num)=>num,
            Err(_)=>{
                println!("pls type number!");
                continue
            }
        };  
    
        println!("You guessed: {}", guess);
    
        match guess.cmp(&secret_number) {
            Ordering::Less => println!("too small"),
            Ordering::Greater => println!("too big"),
            Ordering::Equal => {
                println!("win");
                break;
            }
        }
    }
}
