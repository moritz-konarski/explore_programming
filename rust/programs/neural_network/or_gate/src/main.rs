fn main() {
    let input_options = [[0f64, 1f64], [0f64, 1f64], [1f64, 0f64], [1f64, 1f64]];
    let target_output = [[0f64], [1f64], [1f64], [1f64]];
    let mut weights = [[0.1f64], [0.2f64]];

    let bias: f64 = 0.3;
    let lr: f64 = 0.05;

    for _i in 1..100 {
        let in_o = all_products(input_options, weights);

        let out_o = sigmoid(in_o);

        let error = subtract_array(out_o, target_output);
        println!("{}", sum_array(error));

        let derror_douto = error;
        let douto_dino = sigmoid_derivative(out_o);

        // 4 x 1 matrix
        let deriv = multiply_array(douto_dino, derror_douto);

        // 2 x 4 matrix 
        let inputs = transpose_matrix(input_options);
    }
}

fn multiply_matrix(inputs: [[f64; 4]; 2], deriv: [[f64; 1]; 4]) -> [[f64; 1]; 2] {
    for section in inputs.iter() {

    }
}

fn transpose_matrix(array: [[f64; 2]; 4]) -> [[f64; 4]; 2] {
    [
        [array[0][0], array[1][0], array[2][0], array[3][0]],
        [array[0][1], array[1][1], array[2][1], array[3][1]],
    ]
}

fn sum_array(array: [[f64; 1]; 4]) -> f64 {
    let mut sum = 0f64;
    for number in array.iter() {
        sum += number[0];
    }
    sum
}

fn multiply_array(x: f64, array: [[f64; 1]; 4]) -> [[f64; 1]; 4] {
    [
        [x * array[0][0]],
        [x * array[1][0]],
        [x * array[2][0]],
        [x * array[3][0]],
    ]
}

fn subtract_array(x: f64, array: [[f64; 1]; 4]) -> [[f64; 1]; 4] {
    [
        [x - array[0][0]],
        [x - array[1][0]],
        [x - array[2][0]],
        [x - array[3][0]],
    ]
}

fn all_products(inputs: [[f64; 2]; 4], weights: [[f64; 1]; 2]) -> f64 {
    let mut sum = 0f64;
    for section in inputs.iter() {
        sum += dot_product(*section, weights);
    }
    sum
}

fn dot_product(inputs: [f64; 2], weights: [[f64; 1]; 2]) -> f64 {
    inputs[0] * weights[0][0] + inputs[1] * weights[1][0]
}

fn sigmoid(x: f64) -> f64 {
    1.0f64 / (1.0f64 * (-x).exp())
}

fn sigmoid_derivative(x: f64) -> f64 {
    sigmoid(x) * (1f64 - sigmoid(x))
}
