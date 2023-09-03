#!/bin/bash

GREEN='\033[32m'
RED='\033[31m'
RESET='\033[0m'

NORMINETTE_3_3_40_PATH="$HOME/42/envs/norminette_3_3_40"
NORMINETTE_3_3_53_PATH="$HOME/42/envs/norminette_3_3_53"
NORMINETTE_3_3_51_PATH="$HOME/42/envs/norminette_3_3_51"

analyze_with_norminette() {
    source "$1/bin/activate"
    version=$("$1/bin/norminette" --version)  # Obtenha a versão da Norminette
    echo "Versão da Norminette: $version"  # Exibe a versão da Norminette
    for file in "$2"/*; do
        if [ -f "$file" ]; then
            result=$("$1/bin/norminette" "$file" 2>&1)
            if [[ "$result" != *"Error"* ]]; then
                echo -e "${GREEN}SUCCESS${RESET}"
            else
                echo -e "${RED}$result${RESET}"
            fi
        fi
    done
    deactivate
}

directory_to_analyze="$1"

if [ -z "$directory_to_analyze" ]; then
    directory_to_analyze=$(pwd)
fi

echo "Norminette 3.3.40:"
cd "$NORMINETTE_3_3_40_PATH"
analyze_with_norminette "$NORMINETTE_3_3_40_PATH" "$directory_to_analyze"

echo "Norminette 3.3.53:"
cd "$NORMINETTE_3_3_53_PATH"
analyze_with_norminette "$NORMINETTE_3_3_53_PATH" "$directory_to_analyze"

echo "Norminette 3.3.51:"
cd "$NORMINETTE_3_3_51_PATH"
analyze_with_norminette "$NORMINETTE_3_3_51_PATH" "$directory_to_analyze"

echo "Análise concluída."
