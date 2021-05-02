use std::io;

fn sum1to100() -> u32 {
    let mut sum = 0;
    for elem in 1..100 {
        sum+=elem;
    }
    sum
}

fn str_rev() -> String {
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

fn main() {
    println!("sum of 1 to 100 : {}", sum1to100());
    
    str_rev();
}
