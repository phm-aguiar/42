#!/bin/bash

# Variáveis para os caminhos dos ambientes virtuais da Norminette
NORMINETTE_3_3_40_PATH="$HOME/42/envs/norminette_3_3_40"
NORMINETTE_3_3_53_PATH="$HOME/42/envs/norminette_3_3_53"
NORMINETTE_3_3_51_PATH="$HOME/42/envs/norminette_3_3_51"

# Função para analisar um arquivo com a Norminette 3.3.40
analyze_3_3_40() {
    source $NORMINETTE_3_3_40_PATH/bin/activate
    result=$(norminette "$1" 2>&1)  # Redireciona stdout e stderr para a variável 'result'
    deactivate
    echo "$result"
}

# Função para analisar um arquivo com a Norminette 3.3.53
analyze_3_3_53() {
    source $NORMINETTE_3_3_53_PATH/bin/activate
    result=$(norminette "$1" 2>&1)
    deactivate
    echo "$result"
}

# Função para analisar um arquivo com a Norminette 3.3.51
analyze_3_3_51() {
    source $NORMINETTE_3_3_51_PATH/bin/activate
    result=$(norminette "$1" 2>&1)
    deactivate
    echo "$result"
}

# Loop para analisar todos os arquivos na pasta atual
for file in *; do
    if [ -f "$file" ]; then
        echo "Analisando arquivo: $file"
        echo "Norminette 3.3.40:"
        analyze_3_3_40 "$file"
        echo "Norminette 3.3.53:"
        analyze_3_3_53 "$file"
        echo "Norminette 3.3.51:"
        analyze_3_3_51 "$file"
        echo "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
    fi
done

echo "Análise concluída."

