
# 🃏 Super Trunfo em C

Este projeto é um **jogo de cartas estilo Super Trunfo** desenvolvido em linguagem C como parte do **trabalho de graduação** do curso de **Engenharia de Software da Estácio**.
O objetivo é aplicar conceitos de estrutura de dados, lógica de programação e comparações quantitativas através da simulação de cartas contendo informações de cidades brasileiras.


---

## 📦 Funcionalidades

O programa permite:

- 📥 **Cadastrar novas cartas** com dados detalhados sobre cidades.
- 🔎 **Visualizar todas as cartas** cadastradas.
- ⚔️ **Comparar duas cartas**, escolhendo dois entre cinco atributos.
- 🏆 **Exibir a carta vencedora** ou, em caso de empate, ambas.

## 🛠️ Atributos da Carta

Cada carta representa uma cidade com os seguintes atributos:

- Estado
- Código identificador
- Nome da cidade
- População
- Área territorial (km²)
- PIB total
- Número de pontos turísticos
- Densidade populacional *(calculada automaticamente)*
- PIB per capita *(calculado automaticamente)*
- Super Poder *(calculado com base nos outros atributos)*

## 🔁 Regras de Comparação

Durante a comparação, o usuário escolhe **dois atributos** entre:

1. Densidade populacional *(menor valor vence)*
2. Área territorial *(maior valor vence)*
3. PIB per capita *(maior valor vence)*
4. Pontos turísticos *(maior valor vence)*
5. Super poder *(maior valor vence)*

## 🚀 Como compilar e executar

> ⚠️ **Importante:** A aplicação **não funciona automaticamente ao clicar em "Run" no VS Code**. É necessário compilar e rodar via terminal conforme instruções abaixo.

### 1. Acesse a pasta do projeto:

```bash
cd /caminho/para/o/projeto
```

### 2. Compile o programa com o GCC:

```bash
gcc main.c -o logicaSuperTrunfo
```

> Isso criará um executável chamado `logicaSuperTrunfo` (ou `logicaSuperTrunfo.exe` no Windows).

### 3. Execute o programa:

#### 🔹 No Linux/macOS:
```bash
./logicaSuperTrunfo
```

#### 🔹 No Windows (CMD ou PowerShell):
```cmd
logicaSuperTrunfo.exe
```

---

## 📋 Requisitos

- Sistema com terminal (Linux, macOS, Windows CMD ou PowerShell)
- GCC instalado (verifique com `gcc --version`)
- VS Code ou outro editor apenas para editar — **a execução deve ser feita no terminal**

---

## 🔎 Observações

- Se estiver em Linux/macOS e houver erro de permissão ao rodar, use:
```bash
chmod +x logicaSuperTrunfo
```
- O código foi testado utilizando o compilador GCC. Outros compiladores podem exigir ajustes.

---

## 👨‍💻 Autor

**Everson Dias**  
Aluno de Engenharia de Software – Estácio  
Trabalho de graduação – 2025  

---

✅ Projeto feito com dedicação para demonstrar domínio em programação C estruturada.
