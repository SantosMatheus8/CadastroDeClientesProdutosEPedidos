
--Software desenvolvido no QT Creator com interface gráfica para o usuário. É um sistema de controle de clientes, produtos e pedidos que permite cadastro, remoção, consulta para saber se algum cliente, produto ou pedido foi cadastrado e a listagem, que mostra todos que estão cadastrados.

--Os dados são salvos e a persistência dos dados mantidos pelo sistema será realizada em arquivos texto no formato CSV. Ao iniciar o sistema, ele carrega todos os dados contidos nos respectivos arquivos de dados (ArquivoCadastroClientes.csv, ArquivoCadastrosProdutos.csv, ArquivoCadastrosPedidos.csv), utilizando uma lista enadeada para cada um deles.

--Quando o sistema é iniciado, todos os dados salvos em arquivo .csv, são inseridos na lista, quando o programa para de ser executado, a lista, com todas as alterações é salva novamente no mesmo arquivo, sobrescrevendo eles.

--O sistema possui as classes clientes, pedido produto criadas separadamente, além da lista linear duplamente encadeada com template e seu nó, também foram criadas classe para pessoa fisica e pessoa juridica, sendo assim o sistema aceita cadastro de cliente com CPF e CNPJ, os dois tendo um validador para aceitar apenar CPF e CNPJ válidos.

--Para navegar entre as telas de cliente, produto e pedido basta clicar nos respectivos botões.
<hr>
--Interface inicial :

--A interface inicial possui três botões, Cliente, Produto e Pedido, cada botão vai redirecionar para a página de interação de cada um, clicando em Cliente, podemos cadastrar, consultar, remover e listar os clientes, o mesmo vale para a página de produto e pedido.
<div align-"center">
<img height="500px" width="500px" src="https://user-images.githubusercontent.com/98671908/153858947-412f4474-826b-4a0e-9e9a-c6750e0aa209.jpg">
</div>
<br>
<hr>
--Interface cliente :

--A tela da parte Cliente, possui todos os campos para cadastrar um cliente e são todas obrigatórias, menos a razão social que é apenas para pessoa jurídica, de início todas as opções estão bloqueadas, pois é necessário selecionar no checkbox o que será feito, quando selecionado, todos os itens necessários para cumpir a ação serão liberados.
  
  --Por exemplo se o checkbox Cadastrar for clicado, todos os campos para preencher dados serão liberados e o botão de cadastrar também.
  
  --Não é permitido cadastrar clientes com codigo identificador ou CPF repetidos.
<div align-"center">
<img height="500px" width="500px" src="https://user-images.githubusercontent.com/98671908/153861150-56f2b275-465f-4282-a44b-980a25bbf953.jpg">
</div>

<br>
<hr>
--Interface produto :
--A base é a mesma da parte e Cliente, todos os campos são obrigatórios e apenas o código identificador não pode se repetir.
<div align-"center">
<img height="500px" width="500px" src="https://user-images.githubusercontent.com/98671908/153862445-1c81a330-be74-430e-8239-14521dafb412.jpg">
</div>

<br>
<hr>
--Interface pedido : 
--A base continua a mesma das anteriores e apenas o Codigo identificador do pedido é obrigatório
<div align-"center">
<img height="500px" width="500px" src="https://user-images.githubusercontent.com/98671908/153862750-cf12fd1b-fea5-4661-a009-dbea1e5affce.jpg">
</div>





