use std::io;
use std::fmt;

fn run_sum1to100_example() -> u32 {
    let mut sum = 0;
    for elem in 1..100 {
        sum+=elem;
    }
    sum
}

fn run_str_rev_example() -> String {
    let mut line = String::from("");
    io::stdin().read_line(&mut line)
        .expect("input error");
    let input = line.trim();
    // println!("{}", input);

    let ans: String = input.chars().rev().collect();
    println!("{}", ans);

    let original = "dsd";
    let a = String::from(original);
    return a;
}

fn run_pad_num_example() {
    let mut line = String::from("");
    io::stdin().read_line(&mut line)
        .expect("input error");
    
    println!("{}", line.display_with_pads(Option::from(20)).trim());
}

trait FormatThousand {
    fn display(&self)->String;
    fn display_with_pads(&self, pad:Option<u32>)->String;
}

impl FormatThousand for String {
    fn display(&self)->String {
        return self.display_with_pads(None);
    }
    fn display_with_pads(&self, pad:Option<u32>)->String {
        let mut res=vec![];
        let len:u32 = self.len() as u32;
        let mut reversed = self.chars().rev();
        let pads=match pad {
            Some(value)=>value,
            None=>0
        };

        for i in 0..=pads {
            match reversed.next() {
                Some(value)=>{
                    if i%3==0 && 0<i && i<len-1 {
                        res.push(format!(",{}",value));
                    } else {
                        res.push(format!("{}",value));
                    }
                },
                None=>{
                    res.push(String::from("0"));
                }
            }
        }

        return res
            .into_iter()
            .rev()
            .collect::<std::vec::Vec<std::string::String>>()
            .join("");
    }
}

fn main() {
    // println!("sum of 1 to 100 : {}", run_sum1to100_example());
    
    // run_str_rev_example();

    run_pad_num_example();
}
