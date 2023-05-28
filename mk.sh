find . -type f -name "*.c" -print0 | xargs -0 python3 -m c_formatter_42 > /dev/null 2>&1
find . -type f -name "*.c" -print0 | xargs -0 gcc -Wall -Werror -Wextra -g -lreadline -o minishell