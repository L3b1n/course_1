# Тема №3 - списки

По спискам $L_1 = (a_1, a_2, \dots, a_n)$  и  $L_2 = (b_1, b_2, \dots, b_m)$ построить список $L_3$:

$$
L_3 = 
\begin{equation*}
    \begin{cases}
        (a_1, b_1, a_2, b_2, \dots, a_n, b_n, b_{n + 1}, \dots, b_m), если\ n \textless m; 
        \\
        (a_1, b_1, a_2, b_2, \dots, a_m, b_m, a_{m + 1}, \dots, a_n), если\ n \ge m
    \end{cases}
\end{equation*}
$$