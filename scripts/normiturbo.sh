#!/bin/bash


GREEN='\033[32m'
RED='\033[31m'
RESET='\033[0m'  


NORMINETTE_3_3_40_PATH="$HOME/42/envs/norminette_3_3_40"
NORMINETTE_3_3_53_PATH="$HOME/42/envs/norminette_3_3_53"
NORMINETTE_3_3_51_PATH="$HOME/42/envs/norminette_3_3_51"


analyze_with_norminette() {
    source "$1/bin/activate"
    for file in *; do
        if [ -f "$file" ]; then
            result=$(norminette "$file" 2>&1)
            if [[ "$result" != *"Error"* ]]; then
                echo -e "${GREEN}SUCCESS${RESET}"
            else
                echo -e "${RED}$result${RESET}"
            fi
        fi
    done
    deactivate
}

echo "Norminette 3.3.40:"
analyze_with_norminette "$NORMINETTE_3_3_40_PATH"
echo "Norminette 3.3.53:"
analyze_with_norminette "$NORMINETTE_3_3_53_PATH"
echo "Norminette 3.3.51:"
analyze_with_norminette "$NORMINETTE_3_3_51_PATH"

echo "Análise concluída."
