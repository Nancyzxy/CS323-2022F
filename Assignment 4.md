# Assignment 4

## Ex1: 

```
(1) S' → S
(2) S → aB
(3) B → S ∗ B 
(4) B → ϵ
```

### Q1: parsing table

**$I_0$ =  CLOSURE(S' → ·S) = {S' → ·S, S → · aB}**  

GOTO($I_0$,S) = CLOSURE(S' → S·) = {S' → S·} = $I_1$

GOTO($I_0$,a) = CLOSURE(S → a·B) = {S → a·B, B → ·, B → ·S∗B, S → ·aB} = $I_2$

**$I_1$ = {S' → S·} **  

GOTO($I_1$,$) = accept

**$I_2$ = {S → a·B, B → ·, B → ·S∗B, S → ·aB}** 

GOTO($I_2$,B) = CLOSURE(S → aB·) = {S → aB·} = $I_3$

GOTO($I_2$,S) = CLOSURE(B → S·∗B) = {B → S·∗B} = $I_4$ 

GOTO($I_2$,a) = CLOSURE(S →a·B) = $I_2$

$I_3$ **= {S → aB·}**

**$I_4$ = {B → S·∗B}**

GOTO($I_4$,∗) =  CLOSURE(B → S∗·B) = {B → S∗·B, B → ·S∗B, B →·, S → ·aB} = $I_5$

**$I_5$ = {B → S∗·B, B → ·S∗B, B →·, S → ·aB}**

GOTO($I_5$,S)  = CLOSURE(B → S·∗B) =  $I_4$ 

GOTO($I_5$,B)  = CLOSURE(B → S∗B·) = {B → S∗B·} =  $I_6$ 

GOTO($I_5$,a) = CLOSURE(S → a·B) = $I_2$

**$I_6$ = {B → S∗B·}** 

**LR(0) item sets:** 

```
S' → ·S
S' → S·
S → ·aB 
S → a·B
S → aB·
B → ·S ∗ B 
B → S· ∗ B 
B → S ∗· B 
B → S ∗ B ·
B → ·
follow(B) = {$,*}
follow(S) = {*,$}
```

| STATE | ACTION |      |      | GOTO |      |
| ----- | ------ | ---- | ---- | ---- | ---- |
|       | a      | *    | $    | S    | B    |
| 0     | S2     |      |      | 1    |      |
| 1     |        |      | acc  |      |      |
| 2     | S2     | r4   | r4   | 4    | 3    |
| 3     |        | r2   | r2   |      |      |
| 4     |        | S5   |      |      |      |
| 5     | S2     | r4   | r4   | 4    | 6    |
| 6     |        | r3   | r3   |      |      |

### Q2: It is SLR(1)

### Q3: aaaa*** can be accepted

| Stack         | Input   | symbol | Action                      |
| ------------- | ------- | ------ | --------------------------- |
| 0             | aaaa*** |        | S2                          |
| 0 2           | aaa***  | a      | S2                          |
| 0 2 2         | aa***   | aa     | S2                          |
| 0 2 2 2       | a***    | aaa    | S2                          |
| 0 2 2 2 2     | ***     | aaaa   | r4: B → ϵ, pop 0 state      |
| 0 2 2 2 2 3   | ***     | aaaaB  | r2: S → aB, pop 2 states    |
| 0 2 2 2 4     | ***     | aaaS   | S5                          |
| 0 2 2 2 4 5   | **      | aaaS*  | r4: B → ϵ, pop 0 state      |
| 0 2 2 2 4 5 6 | **      | aaaS*B | r3: B → S ∗ B, pop 3 states |
| 0 2 2 2 3     | **      | aaaB   | r2: S → aB, pop 2 states    |
| 0 2 2 4       | **      | aaS    | S5                          |
| 0 2 2 4 5     | *       | aaS*   | r4: B → ϵ, pop 0 state      |
| 0 2 2 4 5 6   | *       | aaS*B  | r3: B → S ∗ B, pop 3 states |
| 0 2 2 3       | *       | aaB    | r2: S → aB, pop 2 states    |
| 0 2 4         | *       | aS     | S5                          |
| 0 2 4 5       |         | aS*    | r4: B → ϵ, pop 0 state      |
| 0 2 4 5 6     |         | aS*B   | r3: B → S ∗ B, pop 3 states |
| 0 2 3         |         | aB     | r2: S → aB, pop 2 states    |
| 0 1           |         | S      | Accept                      |

## Ex2： 

### Q1 Parse table

```
(1) S' → S
(2) S → aB
(3) B → S ∗ B 
(4) B → ϵ
```

**$I_0$ =  {[S' → ·S,\$], [S → ·aB, $]}**

GOTO($I_0$,S) = CLOSURE([S' → S·, \$]) = {[S' → S·, \$]} = $I_1$

GOTO($I_0$,a) = CLOSURE([S → a·B, \$]) = {[S → a·B, \$], [B → ·,\$], [B → ·S∗B,\$], [S → ·aB,∗]} = $I_2$

$I_1$ = **{[S' → S·, \$]}** 

GOTO($I_1$,$) = accept

 **$I_2$ = {[S → a·B, \$], [B → ·,\$], [B → ·S∗B,\$], [S → ·aB,∗]}**

GOTO($I_2$,B) = CLOSURE([S → aB·,\$]) = {[S → aB·,\$]} = $I_3$

GOTO($I_2$,S) = CLOSURE([B → S·∗B,\$]) = {[B → S·∗B,\$]} = $I_4$ 

GOTO($I_2$,a) = CLOSURE([S →a·B,∗]) = {[S →a·B,∗], [B → ·,∗], [B → ·S∗B,∗], [S → ·aB,∗]}= $I_5$

 **$I_3$ = {[S → aB·,\$]}**

 **$I_4$ = {[B → S·∗B,\$]}**

GOTO($I_4$,∗) = CLOSURE([B → S∗·B,\$]) = {[B → S∗·B,\$], [B → ·S∗B,\$], [B →·,\$], [S → ·aB,∗]} = $I_6$

 **$I_5$ = {[S →a·B,∗], [B → ·,∗], [B → ·S∗B,∗], [S → ·aB,∗]}**

GOTO($I_5$,S)  = CLOSURE([B → S·∗B,∗]) = {[B → S·∗B,∗]} =  $I_7$

GOTO($I_5$,B)  = CLOSURE([S →aB·,∗]) = {[S →aB·,∗]}  =  $I_8$

GOTO($I_5$,a) = CLOSURE([S → a·B,∗]) = $I_5$ 

 $I_6$ = **{[B → S∗·B,\$], [B → ·S∗B,\$], [B →·,\$], [S → ·aB,∗]}** 

GOTO($I_6$,S)  = CLOSURE([B → S·∗B,\$]) =  $I_4$ 

GOTO($I_6$,B)  = CLOSURE([B → S∗B·,\$]) = {[B → S∗B·,\$]} =  $I_9$ 

GOTO($I_6$,a) = CLOSURE([S → a·B,∗]) = $I_5$

$I_7$ = **{[B → S·∗B,∗]}**

GOTO($I_7$,∗) = CLOSURE([B → S∗·B,∗]) = {[B → S∗·B,∗], [B → ·S∗B,∗], [B →·,∗], [S → ·aB,∗]} = $I_{10}$

 **$I_8$ = {[S →aB·,∗]}** 

$I_9$ **= {[B → S∗B·,\$]}**

 $I_{10}$= **{[B → S∗·B,∗], [B → ·S∗B,∗], [B →·,∗], [S → ·aB,∗]}**

GOTO($I_{10}$,S)  = CLOSURE([B → S·∗B,∗]) =  $I_{7}$ 

GOTO($I_{10}$,B)  = CLOSURE([B → S∗B·,∗]) = {[B → S∗B·,∗]} =  $I_{11}$ 

GOTO($I_{10}$,a) = CLOSURE([S → a·B,∗]) = $I_5$

 **$I_{11}$  =   {[B → S∗B·,∗]}** 

**LR(1) item sets:** 

```
[S' → ·S,$] 
[S' → S·,$]
[S → ·aB,$]
[S → a·B,$]
[S → aB·,$]
[S → ·aB,∗]
[S → a·B,∗]
[S → aB·,∗]
[B → ·,$]
[B → ·,∗]
[B → ·S∗B,$]
[B → S·∗B,$]
[B → S∗·B,$]
[B → S∗B·,$]
[B → ·S∗B,∗]
[B → S·∗B,∗]
[B → S∗·B,∗]
[B → S∗B·,∗]
```

| STATE | ACTION |      |      | GOTO |      |
| ----- | ------ | ---- | ---- | ---- | ---- |
|       | a      | *    | $    | S    | B    |
| 0     | S2     |      |      | 1    |      |
| 1     |        |      | acc  |      |      |
| 2     | S5     |      | r4   | 4    | 3    |
| 3     |        |      | r2   |      |      |
| 4     |        | S6   |      |      |      |
| 5     | S5     | r4   |      | 7    | 8    |
| 6     | S5     |      | r4   | 4    | 9    |
| 7     |        | S10  |      |      |      |
| 8     |        | r2   |      |      |      |
| 9     |        |      | r3   |      |      |
| 10    | S5     | r4   |      | 7    | 11   |
| 11    |        | r3   |      |      |      |

### Q2：It is LR(1)

### Q3：aaaa*** can be accepted

| Stack           | Input   | symbol | Action                      |
| --------------- | ------- | ------ | --------------------------- |
| 0               | aaaa*** |        | S2                          |
| 0 2             | aaa***  | a      | S5                          |
| 0 2 5           | aa***   | aa     | S5                          |
| 0 2 5 5         | a***    | aaa    | S5                          |
| 0 2 5 5 5       | ***     | aaaa   | r4: B → ϵ, pop 0 state      |
| 0 2 5 5 5 8     | ***     | aaaaB  | r2: S → aB, pop 2 states    |
| 0 2 5 5 7       | ***     | aaaS   | S10                         |
| 0 2 5 5 7 10    | **      | aaaS*  | r4: B → ϵ, pop 0 state      |
| 0 2 5 5 7 10 11 | **      | aaaS*B | r3: B → S ∗ B, pop 3 states |
| 0 2 5 5 8       | **      | aaaB   | r2: S → aB, pop 2 states    |
| 0 2 5 7         | **      | aaS    | S10                         |
| 0 2 5 7 10      | *       | aaS*   | r4: B → ϵ, pop 0 state      |
| 0 2 5 7 10 11   | *       | aaS*B  | r3: B → S ∗ B, pop 3 states |
| 0 2 5 8         | *       | aaB    | r2: S → aB, pop 2 states    |
| 0 2 4           | *       | aS     | S6                          |
| 0 2 4 6         |         | aS*    | r4: B → ϵ, pop 0 state      |
| 0 2 4 6 9       |         | aS*B   | r3: B → S ∗ B, pop 3 states |
| 0 2 3           |         | aB     | r2: S → aB, pop 2 states    |
| 0 1             |         | S      | Accept                      |

### Ex3： 

### Q1: parse table

**$I_0$ =  {[S' → ·S,\$], [S → ·aB, $]}**

$I_1$ = **{[S' → S·, \$]}** 

$I_2$ **= {[S → a·B, \$], [B → ·, \$], [B → ·S∗B,\$], [S → ·aB,∗]}**

**$I_5$ = {[S → a·B, ∗], [B → ·, ∗], [B → ·S∗B,∗], [S → ·aB,∗]}**

=> $I_{25}$=  **{[S → a·B, ∗/$], [B → ·, ∗/\$], [B → ·S∗B,∗/\$], [S → ·aB,∗]}**

**$I_3$ = {[S → aB·,\$]}**

**$I_8$ = {[S → aB·,∗]}** 

=> $I_{38}$=  **{[S → aB·,∗/$]}**

**$I_4$ = {[B → S·∗B,\$]}**

$I_7$ = **{[B → S·∗B,∗]}**

=> $I_{47}$=  **{[B → S·∗B,∗/$]}**

$I_6$ = **{[B → S∗·B,\$], [B → ·S∗B,\$], [B →·,\$], [S → ·aB,∗]}** 

$I_{10}$= **{[B → S∗·B,∗], [B → ·S∗B,∗], [B →·,∗], [S → ·aB,∗]}**

=> $I_{610}$=  **{[B → S∗·B,∗/\$], [B → ·S∗B,∗/\$], [B →·,∗/\$], [S → ·aB,∗]}**

$I_9$  **=  {[B → S∗B·,\$]}**

**$I_{11}$ =  {[B → S∗B·,∗]}** 

 => $I_{911}$=  **{[B → S∗B·,∗/\$]}**

| STATE | ACTION |      |      | GOTO |      |
| ----- | ------ | ---- | ---- | ---- | ---- |
|       | a      | *    | $    | S    | B    |
| 0     | S25    |      |      | 1    |      |
| 1     |        |      | acc  |      |      |
| 25    | S25    | r4   | r4   | 47   | 38   |
| 38    |        | r2   | r2   |      |      |
| 47    |        | S610 |      |      |      |
| 610   | S25    | r4   | r4   | 47   | 911  |
| 911   |        | r3   | r3   |      |      |

### Q2 The grammar is LALR(1)

### Q3 aaaa*** can be accepted 

| Stack                 | Input   | symbol | Action                      |
| --------------------- | ------- | ------ | --------------------------- |
| 0                     | aaaa*** |        | S25                         |
| 0 25                  | aaa***  | a      | S25                         |
| 0 25 25               | aa***   | aa     | S25                         |
| 0 25 25 25            | a***    | aaa    | S25                         |
| 0 25 25 25 25         | ***     | aaaa   | r4: B → ϵ, pop 0 state      |
| 0 25 25 25 25 38      | ***     | aaaaB  | r2: S → aB, pop 2 states    |
| 0 25 25 25 47         | ***     | aaaS   | S610                        |
| 0 25 25 25 47 610     | **      | aaaS*  | r4: B → ϵ, pop 0 state      |
| 0 25 25 25 47 610 911 | **      | aaaS*B | r3: B → S ∗ B, pop 3 states |
| 0 25 25 25 38         | **      | aaaB   | r2: S → aB, pop 2 states    |
| 0 25 25 47            | **      | aaS    | S610                        |
| 0 25 25 47 610        | *       | aaS*   | r4: B → ϵ, pop 0 state      |
| 0 25 25 47 610 911    | *       | aaS*B  | r3: B → S ∗ B, pop 3 states |
| 0 25 25 38            | *       | aaB    | r2: S → aB, pop 2 states    |
| 0 25 47               | *       | aS     | S610                        |
| 0 25 47 610           |         | aS*    | r4: B → ϵ, pop 0 state      |
| 0 25 47 610 911       |         | aS*B   | r3: B → S ∗ B, pop 3 states |
| 0 25 38               |         | aB     | r2: S → aB, pop 2 states    |
| 0 1                   |         | S      | Accept                      |