# Speed Comparison

Speed comparison of programming languages running the [Leibniz formula for
Pi](https://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80)

Runs per loop: 10,000,000\\
Repetitions  : 10

## Results

### Rust

Time in ms with release code
```
time:   18
time:   16
time:   14
time:   13
time:   13
time:   12
time:   13
time:   12
time:   13
result: 3.1415925535897915
```

### C

Time in s with -Ofast in gcc
```
time:   0.019046
time:   0.015838
time:   0.013665
time:   0.013561
time:   0.013271
time:   0.012944
time:   0.012999
time:   0.012941
time:   0.012981
time:   0.012946
result: 3.141593
```

### Python

Time in s
```
time:  1.1777338399997461
time:  1.1724761679997755
time:  1.1739581079991694
time:  1.174274585000603
time:  1.1827143830005298
time:  1.171137866999743
time:  1.1779313480001292
time:  1.172806899000534
time:  1.1707622909998463
time:  1.1733295590001944
result:  3.1415925535897915
```
