use std::time::Instant;

fn main() {
    let mut sign: i8 = -1;
    let mut pi_over_4: f64 = 1f64;

    for _ in 1..10 {
        pi_over_4 = 1f64;
        let now = Instant::now();
        for i in 1..10_000_000 {
            pi_over_4 += (sign as f64) / ((2 * i + 1) as f64);
            sign *= -1;
        }
        println!("time:   {}", now.elapsed().subsec_millis());
    }
    println!("result: {}", pi_over_4 * 4f64);
}
