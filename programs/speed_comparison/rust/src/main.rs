use std::time::Instant;

const RUN_COUNT: usize = 100;

fn main() {
    let mut sign: i8 = -1;
    let mut pi_over_4: f64 = 1f64;
    let mut timings = [10; RUN_COUNT];

    for n in 1..RUN_COUNT {
        pi_over_4 = 1f64;
        let now = Instant::now();
        for i in 1..10_000_000 {
            pi_over_4 += (sign as f64) / ((2 * i + 1) as f64);
            sign *= -1;
        }
        timings[n] = now.elapsed().subsec_millis();
        println!("time:   {}", now.elapsed().subsec_millis());
    }
    println!("result: {}", pi_over_4 * 4f64);
}
