# AEDA_Proj1
First project from Data structure classes (MIEIC 1st)


## Classes 

### Class empresa 

| Tipo  | Nome  | Descricao  | 
|---|---|---|
| vector  | clients  | vector de clientes  | 
| vector  | servicos  | vector com a lista de serviços disponíveis  |
| vector  | camioes | vector com a frota de camioes|
| metodo | lucro_do_mes( mes)| printa lucro total no mes |
| metodo | info_clients | printa informacao dos N clientes ou de um cliente com nif especifico|
| metodo | info_servicos_feitos | informacao dos servicos feitos |
|uint32_t |capacidade_max  | capacidade maxima dos camioes  | 

### Class cliente

| Tipo  | Nome  | Descricao  | 
|---|---|---|
|  uint8_t| NIF | nif do cliente |
|uint8_t | id | id do cliente | 
| vector | servicos | vector com os serviços requisitados pelos clientes | 


### Class serviços
Nota1: Considere que um serviço de transporte inclui o transporte de um único tipo de produtos.  
Nota2: A escolha de qual camião atende um determinado serviço é efetuada de modo a equilibrar a ocupação de todos os camiões.    
  
| Tipo  | Nome  | Descricao | 
|---|---|---|
|uint8_t | tempo | tempo de viagem, vai receber o ponto de origem e de destino. A partir daí, definir o tempo de viagem | 

### Class camioes

| Tipo  | Nome  | Descricao  | 
|---|---|---|
| metodo, polimorfismo | preco  | preço que os camioes pagam dependendo da distancia e quantidade de mercadoria |

#### Subclasse de camioes

| Tipo  | Nome  | Descricao  | 
|---|---|---|
|class | congelação | produtos congelado  | 
|class | perigosa | produtos perigosos  | 
|class | animais | produtos animais  |
|class | especial | produtos especiais  | 
