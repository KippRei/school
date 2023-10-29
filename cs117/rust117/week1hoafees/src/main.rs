fn main() {
// Variables and consts
let mut years_projected : i32 = Default::default();
let fee_percent_increase : f32 = 0.01;
let orig_member_fee : f32 = 275.00;
let mut member_fee_increase : f32 = 1.01;
let mut curr_member_fee : f32;

println!("Enter Number of Years to Project: ");
let mut user_input: String = Default::default();
std::io::stdin().read_line(&mut user_input).expect("error");

println!("{}", user_input);
years_projected = user_input.trim_end().parse::<i32>().unwrap();

println!("Year    Increase    Amount");
println!("===========================");

for n in 0..years_projected {
        curr_member_fee = orig_member_fee * member_fee_increase;

        println!("{:<8}{:<10}${:<12.2}", n+1, (n+1).to_string() + "%", curr_member_fee);
        member_fee_increase += fee_percent_increase;
    }
}
