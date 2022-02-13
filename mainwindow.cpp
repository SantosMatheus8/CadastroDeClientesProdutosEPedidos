#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)//Quando o programa abre, ele pega os cadastros de CLIENTE, PRODUTO e PEDIDO que estao salvos em arquivo texto e coloca em uma lista
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // //------PEGAR OS CLIENTES NO ARQUIVO---------------------------------------------
    arquivo.open("ArquivoCadastrosClientes.csv", std::ios::in);

    if(!arquivo.is_open()){
        throw QString("ERRO Arquivo nao pode ser aberto");
    }

    std::string linha;
    QStringList listas;
    // lendo do arquivo
    getline(arquivo,linha);

    // Teste de fim do arquivo
    while(!arquivo.eof())
    {
        cliente = new PessoaFisica;
        cliente = new PessoaJuridica;

        listas = QString::fromStdString(linha.c_str()).split(";");
        if(static_cast<PessoaFisica*>(cliente)->validaCPF(listas[3]))//Verifica se o CPF é valido
        {

        (cliente)->setCodigoIdentificador(listas[1].toInt());
        static_cast<PessoaFisica*>(cliente)->setCPF(listas[3]);
        (cliente)->setEmail(listas[5]);
        (cliente)->setEmail(listas[7]);
        (cliente)->setSetor(listas[9]);
        (cliente)->setCidade(listas[11]);
        (cliente)->setEstado(listas[13]);
        (cliente)->setTelefone(listas[15]);
        (cliente)->setNome(listas[17]);



        lista.inserirOrdenado(cliente);
        }
        else if(static_cast<PessoaJuridica*>(cliente)->validaCNPJ(listas[3]))// Valida CNPJ
        {
            (cliente)->setCodigoIdentificador(listas[1].toInt());
            static_cast<PessoaJuridica*>(cliente)->setCNPJ(listas[3]);
            static_cast<PessoaJuridica*>(cliente)->setRazaoSocial(listas[5]);
            (cliente)->setEmail(listas[7]);
            (cliente)->setEmail(listas[9]);
            (cliente)->setSetor(listas[11]);
            (cliente)->setCidade(listas[13]);
            (cliente)->setEstado(listas[15]);
            (cliente)->setTelefone(listas[17]);
            (cliente)->setNome(listas[19]);


            lista.inserirOrdenado(cliente);
        }

        getline(arquivo,linha);

    }
    arquivo.close();


 //------PEGAR OS PRODUTOS NO ARQUIVO---------------------------------------------
    arquivoP.open("ArquivoCadastrosProdutos.csv", std::ios::in);
    QString aux;
    std::string linhaP;
    QStringList list;

    getline(arquivoP, linhaP);
    while(!arquivoP.eof())
    {
        produto = new Produto;
        aux = QString::fromStdString(linhaP);
        list = aux.split(";");
        produto->setCodigoid(list[1].toInt());
        produto->setPreco(list[3].toFloat());
        produto->setDescricao(list[5]);
        produto->setQuant(list[7].toInt());
        listaP.inserirOrdenado(produto);
        getline(arquivoP, linhaP);
    }
    arquivoP.close();

    //------PEGAR OS PEDIDOS NO ARQUIVO---------------------------------------------
       arquivoI.open("ArquivoCadastrosPedidos.csv", std::ios::in);
       QString aux2;
       std::string linhaI;
       QStringList listI;

       getline(arquivoI, linhaI);
       while(!arquivoI.eof())
       {
           pedido = new Pedido;
           aux2 = QString::fromStdString(linhaI);
           listI = aux2.split(";");
           pedido->setCodigoIdentificador(listI[1].toInt());
           pedido->setData(listI[3].toInt());
           pedido->setNumero(listI[5].toInt());
           pedido->setStatus(listI[7]);
           pedido->setCliente(listI[9]);
           pedido->setValorTotal(listI[11].toInt());
           listaI.inserirOrdenado(pedido);
           getline(arquivoI, linhaI);
       }
       arquivoI.close();


}

MainWindow::~MainWindow() //Quando o programa fecha, ele salva todos os CLIENTES, PRODUTOS e PEDIDOS em arquivos texto
{
    //-------------------------------------------Guarda no arquivo a lista de CLIENTES
    QString saida;
    if(!(QString::number(cliente->getCodigoIdentificador()).isEmpty()))
    {
        for (int i = 0; i < lista.getQuantidade();i++)//Imprime minha lista
        {
            saida += "ID: ;" + QString::number(static_cast<Cliente*>(lista[i])->getCodigoIdentificador()) + ";  ";
            if(static_cast<PessoaFisica*>(cliente)->validaCPF((static_cast<PessoaFisica*>(lista[i])->getCPF())))saida += "CPF: ;" + static_cast<PessoaFisica*>(lista[i])->getCPF() + ";  ";
            if(static_cast<PessoaJuridica*>(cliente)->validaCNPJ(static_cast<PessoaJuridica*>(lista[i])->getCNPJ())){saida += "CNPJ: ;" +static_cast<PessoaJuridica*>(lista[i])->getCNPJ() + ";  " ;  saida += "Razao Social: ;" +static_cast<PessoaJuridica*>(lista[i])->getRazaoSocial() + ";  ";}
            saida += "Rua: ;" + static_cast<Cliente*>(lista[i])->getRua() + ";  ";
            saida += "Email: ;" + static_cast<Cliente*>(lista[i])->getEmail() + ";  ";
            saida += "Setor: ;" + static_cast<Cliente*>(lista[i])->getSetor() + ";  ";
            saida += "Cidade: ;" + static_cast<Cliente*>(lista[i])->getCidade() + ";  ";
            saida += "Estado: ;" + static_cast<Cliente*>(lista[i])->getEstado() + ";  ";
            saida += "Telefone: ;" + static_cast<Cliente*>(lista[i])->getTelefone() + ";  ";
            saida += "Nome: ;" + static_cast<Cliente*>(lista[i])->getNome() + "  ";
            saida += "\n";
        }

        //----------------------------------------------------

        //Meu Arquivo
        remove("ArquivoCadastrosClientes.csv");
        arquivo.open("ArquivoCadastrosClientes.csv", std::ios::app);

        arquivo << saida.toStdString();

        arquivo.close();
    }


    //-------------------------------------------------Guarda no arquivo a lista de PRODUTOS
    QString saidaProduto;
    for(int i = 0; i < listaP.getQuantidade(); i++)
    {
        saidaProduto += "Codigo id: ;" + QString::number(static_cast<Produto*>(listaP[i])->getCodigoid()) + ";";
        saidaProduto += "Preco : ;" + QString::number(static_cast<Produto*>(listaP[i])->getPreco()) + ";";
        saidaProduto += "Descricao : ;" + static_cast<Produto*>(listaP[i])->getDescricao() + ";";
        saidaProduto += "Quantidade : ;" + QString::number(static_cast<Produto*>(listaP[i])->getQuant()) + ";";
        saidaProduto += "\n";
    }
    remove("ArquivoCadastrosProdutos.csv");
    arquivoP.open("ArquivoCadastrosProdutos.csv", std::ios::app);
    arquivoP << saidaProduto.toStdString();
    arquivoP.close();


    //-------------------------------------------------Guarda no arquivo a lista de PEDIDOS
    QString saidaPedido;
    for(int i = 0; i < listaI.getQuantidade(); i++)
    {
        saidaPedido += "ID do Pedido : ;" + QString::number(listaI[i]->getCodigoIdentificador()) + ";";
        saidaPedido += "Data: ;" + (QString::number(listaI[i]->getData())) + ";";
        saidaPedido += "ID Produto : ;" + QString::number((listaI[i]->getNumero())) + ";";
        saidaPedido += "Status : ;" + (listaI[i]->getStatus()) + ";";
        saidaPedido += "ID do Cliente : ;" + (listaI[i]->getCliente()) + ";";
        saidaPedido += "Valor Total : ;" + QString::number(listaI[i]->getValorTotal()) + ";";
        saidaPedido += "\n";
    }
    remove("ArquivoCadastrosPedidos.csv");
    arquivoI.open("ArquivoCadastrosPedidos.csv", std::ios::app);
    arquivoI << saidaPedido.toStdString();
    arquivoI.close();


    delete ui;
}


void MainWindow::on_pushButtonCliente_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEditRua->setEnabled(false);
    ui->lineEditNome->setEnabled(false);
    ui->lineEdit_2Setor->setEnabled(false);
    ui->lineEdit_6Email->setEnabled(false);
    ui->lineEditCodigoID->setEnabled(false);
    ui->lineEdit_3Cidade->setEnabled(false);
    ui->lineEdit_4Estado->setEnabled(false);
    ui->lineEdit_5Telefone->setEnabled(false);
    ui->lineEditRazaoSocial->setEnabled(false);
    ui->lineEditNumeroDeCadastro->setEnabled(false);
    ui->pushButtonListar->setEnabled(false);
    ui->pushButton_2Remover->setEnabled(false);
    ui->pushButton_3Consultar->setEnabled(false);
    ui->pushButtonCadastrarCliente->setEnabled(false);

}


void MainWindow::on_pushButton_2Produto_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->lineEditPreco->setEnabled(false);
    ui->lineEditCodigoID_2->setEnabled(false);
    ui->lineEditDescricaoProduto->setEnabled(false);
    ui->lineEditQuantidadeEmEstoque->setEnabled(false);
    ui->pushButtonCadastrarProduto->setEnabled(false);
    ui->pushButtonRemoverProduto->setEnabled(false);
    ui->pushButton_3ListarProduto->setEnabled(false);
    ui->pushButton_2ConsultarProduto->setEnabled(false);

}

void MainWindow::on_pushButton_3Pedido_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->lineEditQuantidadeEmEstoque->setEnabled(false);
    ui->lineEditCodigoDoCliente->setEnabled(false);
    ui->lineEditCodigoID_3->setEnabled(false);
    ui->lineEditCodigoProduto->setEnabled(false);
    //ui->lineEditQuantidadeProduto->setEnabled(false);
    ui->pushButton_2CadastrarPedido->setEnabled(false);
    ui->pushButton_3ListarPedido->setEnabled(false);
    ui->pushButtonConsultarPedido->setEnabled(false);
    ui->pushButton_2RemoverPedido->setEnabled(false);
    ui->lineEditStatus->setEnabled(false);
    ui->lineEditData->setEnabled(false);
    ui->lineEdit_2ValorTotal->setEnabled(false);
}

//---------------------------------------CLIENTE--------------------------------------------------------------------------
//---------------------------------------CLIENTE--------------------------------------------------------------------------
//---------------------------------------CLIENTE--------------------------------------------------------------------------
//---------------------------------------CLIENTE--------------------------------------------------------------------------
//---------------------------------------CLIENTE--------------------------------------------------------------------------
//---------------------------------------CLIENTE--------------------------------------------------------------------------

void MainWindow::on_checkBox_6Cadastrar_clicked()
{
    ui->lineEditRua->setEnabled(true);
    ui->lineEditNome->setEnabled(true);
    ui->lineEdit_2Setor->setEnabled(true);
    ui->lineEdit_6Email->setEnabled(true);
    ui->lineEditCodigoID->setEnabled(true);
    ui->lineEdit_3Cidade->setEnabled(true);
    ui->lineEdit_4Estado->setEnabled(true);
    ui->lineEdit_5Telefone->setEnabled(true);
    ui->lineEditRazaoSocial->setEnabled(true);
    ui->lineEditNumeroDeCadastro->setEnabled(true);
    ui->pushButtonListar->setEnabled(false);
    ui->pushButton_2Remover->setEnabled(false);
    ui->pushButton_3Consultar->setEnabled(false);
    ui->pushButtonCadastrarCliente->setEnabled(true);
}

void MainWindow::on_checkBox_5Consultar_clicked()
{
    ui->lineEditRua->setEnabled(false);
    ui->lineEditNome->setEnabled(false);
    ui->lineEdit_2Setor->setEnabled(false);
    ui->lineEdit_6Email->setEnabled(false);
    ui->lineEditCodigoID->setEnabled(false);
    ui->lineEdit_3Cidade->setEnabled(false);
    ui->lineEdit_4Estado->setEnabled(false);
    ui->lineEdit_5Telefone->setEnabled(false);
    ui->lineEditRazaoSocial->setEnabled(false);
    ui->lineEditNumeroDeCadastro->setEnabled(true);
    ui->pushButtonListar->setEnabled(false);
    ui->pushButton_2Remover->setEnabled(false);
    ui->pushButton_3Consultar->setEnabled(true);
    ui->pushButtonCadastrarCliente->setEnabled(false);
}

void MainWindow::on_checkBox_4Remover_clicked()
{
    ui->lineEditRua->setEnabled(false);
    ui->lineEditNome->setEnabled(false);
    ui->lineEdit_2Setor->setEnabled(false);
    ui->lineEdit_6Email->setEnabled(false);
    ui->lineEditCodigoID->setEnabled(false);
    ui->lineEdit_3Cidade->setEnabled(false);
    ui->lineEdit_4Estado->setEnabled(false);
    ui->lineEdit_5Telefone->setEnabled(false);
    ui->lineEditRazaoSocial->setEnabled(false);
    ui->lineEditNumeroDeCadastro->setEnabled(true);
    ui->pushButtonListar->setEnabled(false);
    ui->pushButton_2Remover->setEnabled(true);
    ui->pushButton_3Consultar->setEnabled(false);
    ui->pushButtonCadastrarCliente->setEnabled(false);
}

void MainWindow::on_checkBox_7Listar_clicked()
{
    ui->lineEditRua->setEnabled(false);
    ui->lineEditNome->setEnabled(false);
    ui->lineEdit_2Setor->setEnabled(false);
    ui->lineEdit_6Email->setEnabled(false);
    ui->lineEditCodigoID->setEnabled(false);
    ui->lineEdit_3Cidade->setEnabled(false);
    ui->lineEdit_4Estado->setEnabled(false);
    ui->lineEdit_5Telefone->setEnabled(false);
    ui->lineEditRazaoSocial->setEnabled(false);
    ui->lineEditNumeroDeCadastro->setEnabled(false);
    ui->pushButtonListar->setEnabled(true);
    ui->pushButton_2Remover->setEnabled(false);
    ui->pushButton_3Consultar->setEnabled(false);
    ui->pushButtonCadastrarCliente->setEnabled(false);
}

void MainWindow::on_pushButtonCadastrarCliente_clicked()//Botao que realiza o cadastro dos clientes
{
    try
    {
        cliente = new PessoaFisica;
        cliente = new PessoaJuridica;


        if(ui->lineEditRua->QLineEdit::text().isEmpty()){throw QString("Campo RUA vazio");}
        if(ui->lineEditNome->QLineEdit::text().isEmpty()){throw QString("Campo NOME vazio");}
        if(ui->lineEdit_2Setor->QLineEdit::text().isEmpty()){throw QString("Campo SETOR vazio");}
        if(ui->lineEdit_6Email->QLineEdit::text().isEmpty()){throw QString("Campo EMAIL vazio");}
        if(ui->lineEditCodigoID->QLineEdit::text().isEmpty()){throw QString("Campo CODIGO ID vazio");}
        if(ui->lineEdit_3Cidade->QLineEdit::text().isEmpty()){throw QString("Campo CIDADE vazio");}
        if(ui->lineEdit_4Estado->QLineEdit::text().isEmpty()){throw QString("Campo ESTADO vazio");}
        if(ui->lineEdit_5Telefone->QLineEdit::text().isEmpty()){throw QString("Campo TELEFONE vazio");}



        //----------------------------------------------------------------------------------------------------------------------------------------

        //CPF
        if(static_cast<PessoaFisica*>(cliente)->validaCPF((ui->lineEditNumeroDeCadastro->QLineEdit::text())))//Verifica se o CPF é valido
        {


            cliente->setRua(ui->lineEditRua->QLineEdit::text());
            cliente->setEmail(ui->lineEdit_6Email->QLineEdit::text());
            cliente->setSetor(ui->lineEdit_2Setor->QLineEdit::text());
            cliente->setCidade(ui->lineEdit_3Cidade->QLineEdit::text());
            cliente->setEstado(ui->lineEdit_4Estado->QLineEdit::text());
            cliente->setTelefone(ui->lineEdit_5Telefone->QLineEdit::text());
            cliente->setCodigoIdentificador(ui->lineEditCodigoID->QLineEdit::text().toInt());
            cliente->setNome(ui->lineEditNome->QLineEdit::text());

            static_cast<PessoaFisica*>(cliente)->setCPF((ui->lineEditNumeroDeCadastro->QLineEdit::text()));

            for (int i = 0; i < lista.getQuantidade();i++) //Verifica se o ID e o CPF ja estao cadastrados
            {
                if(static_cast<PessoaFisica*>(cliente)->getCodigoIdentificador() == static_cast<PessoaFisica*>(lista[i])->getCodigoIdentificador())
                {
                    ui->lineEditCodigoID->setFocus();
                    throw QString("Codigo identificador invalido");
                    return;
                }

                else if(static_cast<PessoaFisica*>(cliente)->getCPF() == static_cast<PessoaFisica*>(lista[i])->getCPF())
                {
                    ui->lineEditNumeroDeCadastro->setFocus();
                    throw QString("CPF ja esta cadastrado");
                    return;
                }
            }

            lista.inserirOrdenado(cliente);

        }

        //---------------------------------------------------------------------------------------------------------------------------------------------------
        //CNPJ
         if(static_cast<PessoaJuridica*>(cliente)->validaCNPJ((ui->lineEditNumeroDeCadastro->QLineEdit::text())))// Valida CNPJ
        {

            if(ui->lineEditRazaoSocial->QLineEdit::text().isEmpty()){throw QString("Campo RAZAO SOCIAL vazio");}
            cliente->setRua(ui->lineEditRua->QLineEdit::text());
            cliente->setEmail(ui->lineEdit_6Email->QLineEdit::text());
            cliente->setSetor(ui->lineEdit_2Setor->QLineEdit::text());
            cliente->setCidade(ui->lineEdit_3Cidade->QLineEdit::text());
            cliente->setEstado(ui->lineEdit_4Estado->QLineEdit::text());
            cliente->setTelefone(ui->lineEdit_5Telefone->QLineEdit::text());
            cliente->setCodigoIdentificador(ui->lineEditCodigoID->QLineEdit::text().toInt());
            cliente->setNome(ui->lineEditNome->QLineEdit::text());

            static_cast<PessoaJuridica*>(cliente)->setCNPJ((ui->lineEditNumeroDeCadastro->QLineEdit::text()));
            static_cast<PessoaJuridica*>(cliente)->setRazaoSocial((ui->lineEditRazaoSocial->QLineEdit::text()));

            for (int i = 0; i < lista.getQuantidade();i++)//Verifica se o ID e o CNPJ ja estao cadastrados
            {
                if(static_cast<PessoaJuridica*>(cliente)->getCodigoIdentificador() == static_cast<PessoaJuridica*>(lista[i])->getCodigoIdentificador())
                {
                    ui->lineEditCodigoID->setFocus();
                    throw QString("Codigo identificador invalido");
                    return;
                }

                else if(static_cast<PessoaJuridica*>(cliente)->getCNPJ() == static_cast<PessoaJuridica*>(lista[i])->getCNPJ())
                {
                    ui->lineEditNumeroDeCadastro->setFocus();
                    throw QString("CNPJ ja esta cadastrado");
                    return;
                }
            }

            lista.inserirOrdenado(cliente);
        }
        //-----------------------------------------------------------------------------------------------------------------

        //Se o texto digitado em NumeroDeCadastro nao for nem CPF nem CNPJ o programa lança excessao
        else if(static_cast<PessoaFisica*>(cliente)->validaCPF((ui->lineEditNumeroDeCadastro->QLineEdit::text())) == false && static_cast<PessoaJuridica*>(cliente)->validaCNPJ((ui->lineEditNumeroDeCadastro->QLineEdit::text())) == false)
        {
            throw QString("Numero de cadastro invalido");
        }
    } catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_3Consultar_clicked()//Botao que consulta se um cliente está cadastrado
{
    try {
        cliente = new PessoaFisica;
        cliente = new PessoaJuridica;
        QString saida;
        int j = 0;
        static_cast<PessoaFisica*>(cliente)->setCPF((ui->lineEditNumeroDeCadastro->QLineEdit::text()));
        static_cast<PessoaJuridica*>(cliente)->setCNPJ((ui->lineEditNumeroDeCadastro->QLineEdit::text()));
        if(ui->lineEditNumeroDeCadastro->QLineEdit::text() == "") throw QString("Numero de cadastro nao encontrado");
        for (int i = 0; i < lista.getQuantidade();i++) //Verifica se o ID e o CPF ja estao cadastrados
        {


             if(static_cast<PessoaFisica*>(cliente)->getCPF() == static_cast<PessoaFisica*>(lista[i])->getCPF())
            {
                j = 1;
                saida += "CPF encontrado: \n";
                saida += "ID: " + QString::number(static_cast<Cliente*>(lista[i])->getCodigoIdentificador()) + " | ";
                saida += "CPF: " + static_cast<PessoaFisica*>(lista[i])->getCPF() + " | ";
                saida += "Rua: " + static_cast<Cliente*>(lista[i])->getRua() + " | ";
                saida += "Email: " + static_cast<Cliente*>(lista[i])->getEmail() + " | ";
                saida += "Setor: " + static_cast<Cliente*>(lista[i])->getSetor() + " | ";
                saida += "Cidade: " + static_cast<Cliente*>(lista[i])->getCidade() + " | ";
                saida += "Estado: " + static_cast<Cliente*>(lista[i])->getEstado() + " | ";
                saida += "Telefone: " + static_cast<Cliente*>(lista[i])->getTelefone() + " | ";
                saida += "Nome: " + static_cast<Cliente*>(lista[i])->getNome() + "  ";
                saida += "\n";

            }
            if(static_cast<PessoaJuridica*>(cliente)->getCNPJ() == static_cast<PessoaJuridica*>(lista[i])->getCNPJ())
             {
                j = 1;
                saida += "CNPJ encontrado";
                saida += "ID: " + QString::number(static_cast<Cliente*>(lista[i])->getCodigoIdentificador()) + " | ";
                saida += "CPF: " + static_cast<PessoaJuridica*>(lista[i])->getCNPJ() + " | ";
                saida += "Rua: " + static_cast<Cliente*>(lista[i])->getRua() + " | ";
                saida += "Email: " + static_cast<Cliente*>(lista[i])->getEmail() + " | ";
                saida += "Setor: " + static_cast<Cliente*>(lista[i])->getSetor() + " | ";
                saida += "Cidade: " + static_cast<Cliente*>(lista[i])->getCidade() + " | ";
                saida += "Estado: " + static_cast<Cliente*>(lista[i])->getEstado() + " | ";
                saida += "Telefone: " + static_cast<Cliente*>(lista[i])->getTelefone() + " | ";
                saida += "Nome: " + static_cast<Cliente*>(lista[i])->getNome() + "  ";
                saida += "\n";

             }
            ui->textEditSaida_2->setText(saida);

        }
        if(j == 0)throw QString("Numero de cadastro nao encontrado");
        } catch (QString &erro) {
            QMessageBox::information(this, "erro", erro);
        }
}



void MainWindow::on_pushButton_2Remover_clicked() //Botao que remove um cliente
{
    try {
  cliente = new PessoaFisica;
  cliente = new PessoaJuridica;
        int j = 0;
        static_cast<PessoaFisica*>(cliente)->setCPF((ui->lineEditNumeroDeCadastro->QLineEdit::text()));
        static_cast<PessoaJuridica*>(cliente)->setCNPJ((ui->lineEditNumeroDeCadastro->QLineEdit::text()));
        if(ui->lineEditNumeroDeCadastro->QLineEdit::text() == "") throw QString("Numero de cadastro nao encontrado");
        for (int i = 0; i < lista.getQuantidade();i++) //Verifica se o ID e o CPF ja estao cadastrados
        {


            if(static_cast<PessoaFisica*>(cliente)->getCPF() == static_cast<PessoaFisica*>(lista[i])->getCPF())
            {
                j = 1;
                lista.retirarPosicao(i);
//                throw QString("CPF removido");
                QString saida = "CPF removido com sucesso : \n";
                saida += "CPF : " + static_cast<PessoaFisica*>(cliente)->getCPF() + " | ";
                saida += "Nome : " + static_cast<PessoaFisica*>(cliente)->getNome() + " | ";
                saida += "Rua : " + static_cast<PessoaFisica*>(cliente)->getRua() + " | ";
                saida += "Email : " + static_cast<PessoaFisica*>(cliente)->getEmail() + " | ";
                saida += "Setor : " + static_cast<PessoaFisica*>(cliente)->getSetor() + " | ";
                saida += "Cidade : " + static_cast<PessoaFisica*>(cliente)->getCidade() + " | ";
                saida += "Estado : " + static_cast<PessoaFisica*>(cliente)->getEstado() + " | ";
                saida += "Telefone : " + static_cast<PessoaFisica*>(cliente)->getTelefone() + " | ";
                saida += "Codigo Identificador : " + QString::number(static_cast<PessoaFisica*>(cliente)->getCodigoIdentificador()) + "  ";
                ui->textEditSaida_2->setText(saida);
                return;
            }
            else if(static_cast<PessoaJuridica*>(cliente)->getCNPJ() == static_cast<PessoaJuridica*>(lista[i])->getCNPJ())
            {
                j = 1;
                lista.retirarPosicao(i);
//                throw QString("CNPJ removido");
                QString saida = "CNPJ removido com sucesso : \n";
                saida += "CNPJ : " + static_cast<PessoaJuridica*>(cliente)->getCNPJ() + " | ";
                saida += "Nome : " + static_cast<PessoaJuridica*>(cliente)->getNome() + " | ";
                saida += "Rua : " + static_cast<PessoaJuridica*>(cliente)->getRua() + " | ";
                saida += "Email : " + static_cast<PessoaJuridica*>(cliente)->getEmail() + " | ";
                saida += "Setor : " + static_cast<PessoaJuridica*>(cliente)->getSetor() + " | ";
                saida += "Cidade : " + static_cast<PessoaJuridica*>(cliente)->getCidade() + " | ";
                saida += "Estado : " + static_cast<PessoaJuridica*>(cliente)->getEstado() + " | ";
                saida += "Telefone : " + static_cast<PessoaJuridica*>(cliente)->getTelefone() + " | ";
                saida += "Codigo Identificador : " + QString::number(static_cast<PessoaJuridica*>(cliente)->getCodigoIdentificador()) + "  ";
                ui->textEditSaida_2->setText(saida);
                return;
            }

        } if(j == 0 || ui->lineEditNumeroDeCadastro->QLineEdit::text() == "") throw QString("Numero de cadastro nao encontrado");

        } catch (QString &erro) {
            QMessageBox::information(this, "erro", erro);
        }
}

void MainWindow::on_pushButtonListar_clicked()//Botao que lista os clientes cadastrados
{
    try {
        ui->textEditSaida->clear();
        QString saidaTextEdit;

        for (int i = 0; i < lista.getQuantidade();i++)//Imprime minha lista
        {
            saidaTextEdit += "ID: " + QString::number(static_cast<Cliente*>(lista[i])->getCodigoIdentificador()) + " | ";
            if(static_cast<PessoaFisica*>(cliente)->validaCPF((static_cast<PessoaFisica*>(lista[i])->getCPF())))saidaTextEdit += "CPF: " + static_cast<PessoaFisica*>(lista[i])->getCPF() + " | ";
            if(static_cast<PessoaJuridica*>(cliente)->validaCNPJ(static_cast<PessoaJuridica*>(lista[i])->getCNPJ())){saidaTextEdit += "CNPJ: " +static_cast<PessoaJuridica*>(lista[i])->getCNPJ() + " | " ;  saidaTextEdit += "Razao Social: " +static_cast<PessoaJuridica*>(lista[i])->getRazaoSocial() + " | ";}
            saidaTextEdit += "Rua: " + static_cast<Cliente*>(lista[i])->getRua() + " | ";
            saidaTextEdit += "Email: " + static_cast<Cliente*>(lista[i])->getEmail() + " | ";
            saidaTextEdit += "Setor: " + static_cast<Cliente*>(lista[i])->getSetor() + " | ";
            saidaTextEdit += "Cidade: " + static_cast<Cliente*>(lista[i])->getCidade() + " | ";
            saidaTextEdit += "Estado: " + static_cast<Cliente*>(lista[i])->getEstado() + " | ";
            saidaTextEdit += "Telefone: " + static_cast<Cliente*>(lista[i])->getTelefone() + " | ";
            saidaTextEdit += "Nome: " + static_cast<Cliente*>(lista[i])->getNome() + "  ";
            saidaTextEdit += "\n";
            saidaTextEdit += "---------------------------------------------------------------------------------------------------------------\n";
        }
        ui->textEditSaida_2->setText(saidaTextEdit);
    } catch (QString &erro) {
        QMessageBox::information(this, "erro", erro);
    }
}


void MainWindow::on_checkBoxCadastrarProduto_clicked()
{
    ui->lineEditPreco->setEnabled(true);
    ui->lineEditCodigoID_2->setEnabled(true);
    ui->lineEditDescricaoProduto->setEnabled(true);
    ui->lineEditQuantidadeEmEstoque->setEnabled(true);
    ui->pushButtonCadastrarProduto->setEnabled(true);
    ui->pushButtonRemoverProduto->setEnabled(false);
    ui->pushButton_3ListarProduto->setEnabled(false);
    ui->pushButton_2ConsultarProduto->setEnabled(false);
}

void MainWindow::on_checkBox_2ConsultarProduto_clicked()
{
    ui->lineEditPreco->setEnabled(false);
    ui->lineEditCodigoID_2->setEnabled(true);
    ui->lineEditDescricaoProduto->setEnabled(false);
    ui->lineEditQuantidadeEmEstoque->setEnabled(false);
    ui->pushButtonCadastrarProduto->setEnabled(false);
    ui->pushButtonRemoverProduto->setEnabled(false);
    ui->pushButton_3ListarProduto->setEnabled(false);
    ui->pushButton_2ConsultarProduto->setEnabled(true);
}

void MainWindow::on_checkBox_3RemoverProduto_clicked()
{
    ui->lineEditPreco->setEnabled(false);
    ui->lineEditCodigoID_2->setEnabled(true);
    ui->lineEditDescricaoProduto->setEnabled(false);
    ui->lineEditQuantidadeEmEstoque->setEnabled(false);
    ui->pushButtonCadastrarProduto->setEnabled(false);
    ui->pushButtonRemoverProduto->setEnabled(true);
    ui->pushButton_3ListarProduto->setEnabled(false);
    ui->pushButton_2ConsultarProduto->setEnabled(false);
}

void MainWindow::on_checkBox_4ListarProduto_clicked()
{
    ui->lineEditPreco->setEnabled(false);
    ui->lineEditCodigoID_2->setEnabled(false);
    ui->lineEditDescricaoProduto->setEnabled(false);
    ui->lineEditQuantidadeEmEstoque->setEnabled(false);
    ui->pushButtonCadastrarProduto->setEnabled(false);
    ui->pushButtonRemoverProduto->setEnabled(false);
    ui->pushButton_3ListarProduto->setEnabled(true);
    ui->pushButton_2ConsultarProduto->setEnabled(false);
}

void MainWindow::on_checkBoxCadastrarPedido_clicked()
{
    ui->lineEditQuantidadeEmEstoque->setEnabled(true);
    ui->lineEditCodigoDoCliente->setEnabled(true);
    ui->lineEditCodigoID_3->setEnabled(true);
    ui->lineEditCodigoProduto->setEnabled(true);
    //ui->lineEditQuantidadeProduto->setEnabled(true);
    ui->pushButton_2CadastrarPedido->setEnabled(true);
    ui->pushButton_3ListarPedido->setEnabled(false);
    ui->pushButtonConsultarPedido->setEnabled(false);
    ui->pushButton_2RemoverPedido->setEnabled(false);
    ui->lineEditStatus->setEnabled(true);
    ui->lineEditData->setEnabled(true);
    ui->lineEdit_2ValorTotal->setEnabled(true);
}

void MainWindow::on_checkBox_2ConsultarPedido_clicked()
{
    ui->lineEditQuantidadeEmEstoque->setEnabled(false);
    ui->lineEditCodigoDoCliente->setEnabled(false);
    ui->lineEditCodigoID_3->setEnabled(true);
    ui->lineEditCodigoProduto->setEnabled(false);
    //ui->lineEditQuantidadeProduto->setEnabled(false);
    ui->pushButton_2CadastrarPedido->setEnabled(false);
    ui->pushButton_3ListarPedido->setEnabled(false);
    ui->pushButtonConsultarPedido->setEnabled(true);
    ui->pushButton_2RemoverPedido->setEnabled(false);
    ui->lineEditStatus->setEnabled(false);
    ui->lineEditData->setEnabled(false);
    ui->lineEdit_2ValorTotal->setEnabled(false);
}

void MainWindow::on_checkBox_3RemoverPedido_clicked()
{
    ui->lineEditQuantidadeEmEstoque->setEnabled(false);
    ui->lineEditCodigoDoCliente->setEnabled(false);
    ui->lineEditCodigoID_3->setEnabled(true);
    ui->lineEditCodigoProduto->setEnabled(false);
    //ui->lineEditQuantidadeProduto->setEnabled(false);
    ui->pushButton_2CadastrarPedido->setEnabled(false);
    ui->pushButton_3ListarPedido->setEnabled(false);
    ui->pushButtonConsultarPedido->setEnabled(false);
    ui->pushButton_2RemoverPedido->setEnabled(true);
    ui->lineEditStatus->setEnabled(false);
    ui->lineEditData->setEnabled(false);
    ui->lineEdit_2ValorTotal->setEnabled(false);
}

void MainWindow::on_checkBox_4ListarPedido_clicked()
{
    ui->lineEditQuantidadeEmEstoque->setEnabled(false);
    ui->lineEditCodigoDoCliente->setEnabled(false);
    ui->lineEditCodigoID_3->setEnabled(false);
    ui->lineEditCodigoProduto->setEnabled(false);
    //ui->lineEditQuantidadeProduto->setEnabled(false);
    ui->pushButton_2CadastrarPedido->setEnabled(false);
    ui->pushButton_3ListarPedido->setEnabled(true);
    ui->pushButtonConsultarPedido->setEnabled(false);
    ui->pushButton_2RemoverPedido->setEnabled(false);
    ui->lineEditStatus->setEnabled(false);
    ui->lineEditData->setEnabled(false);
    ui->lineEdit_2ValorTotal->setEnabled(false);
}
//---------------------------------------PRODUTO--------------------------------------------------------------------------
//---------------------------------------PRODUTO--------------------------------------------------------------------------
//---------------------------------------PRODUTO--------------------------------------------------------------------------
//---------------------------------------PRODUTO--------------------------------------------------------------------------
//---------------------------------------PRODUTO--------------------------------------------------------------------------
//---------------------------------------PRODUTO--------------------------------------------------------------------------


void MainWindow::on_pushButtonCadastrarProduto_clicked()//Botao que cadastra produtos
{
    try {

        produto = new Produto;

        QString textoPrecoProduto = ui->lineEditPreco->QLineEdit::text();
        produto->setPreco(textoPrecoProduto.toFloat());

        QString textoCodigoID = ui->lineEditCodigoID_2->QLineEdit::text();
        produto->setCodigoid(textoCodigoID.toInt());

        QString textoQuantidadeEmEstoque = ui->lineEditQuantidadeEmEstoque->QLineEdit::text();
        produto->setQuant(textoQuantidadeEmEstoque.toInt());

        QString textoDescricaoProduto = ui->lineEditDescricaoProduto->QLineEdit::text();
        produto->setDescricao(textoDescricaoProduto);

        for(int i = 0; i < listaP.getQuantidade(); i++)
        {
            if(produto->getCodigoid() == static_cast<Produto*>(listaP[i])->getCodigoid())
            {
                throw QString("Codigo ID ja esta cadastrado");
                return;
            }
        }

        if(textoCodigoID.isEmpty()){throw QString("Campo CODIGO IDENTIFICADOR vazio"); return;}
        if(textoPrecoProduto.isEmpty()){ throw QString("Campo PREÇO vazio"); return;}
        if(textoDescricaoProduto.isEmpty()){ throw QString("Campo DESCRIÇAO DO PRODUTO vazio"); return;}
        if(textoQuantidadeEmEstoque.isEmpty()){ throw QString("Campo QUANTIDADE EM ESTOQUE vazio"); return;}

        listaP.inserirOrdenado(produto);

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_3ListarProduto_clicked()//Botao que lista os produtos cadastrados
{
    try
    {
        QString saida;
        for(int i = 0; i < listaP.getQuantidade(); i++)
        {
            saida += "ID: " + QString::number(static_cast<Produto*>(listaP[i])->getCodigoid()) + " | ";
            saida += "Preco: " + QString::number(static_cast<Produto*>(listaP[i])->getPreco()) + " | ";
            saida += "Descricao: " + static_cast<Produto*>(listaP[i])->getDescricao() + " | ";
            saida += "Quantidade: " + QString::number(static_cast<Produto*>(listaP[i])->getQuant()) + "  ";
            saida += "-------------------------------------------------------------------------------------------------------------\n";
            saida += "\n";
        }
        ui->textEditSaida->setText(saida);
    } catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_2ConsultarProduto_clicked()//Botao que consulta se um produto esta cadastrado
{
    try {
    produto = new Produto;
    QString saida;
    produto->setCodigoid(ui->lineEditCodigoID_2->QLineEdit::text().toInt());
    int j = 0;
    for(int i = 0; i < listaP.getQuantidade(); i++)
    {
        if(QString::number(produto->getCodigoid()) == QString::number((listaP[i])->getCodigoid()))
        {
            saida += "Codigo ID esta cadastrado: \n";
            saida += "ID: " + QString::number(static_cast<Produto*>(listaP[i])->getCodigoid()) + " | ";
            saida += "Preco: " + QString::number(static_cast<Produto*>(listaP[i])->getPreco()) + " | ";
            saida += "Descricao: " + static_cast<Produto*>(listaP[i])->getDescricao() + " | ";
            saida += "Quantidade: " + QString::number(static_cast<Produto*>(listaP[i])->getQuant()) + "  ";
            saida += "\n";
            j = 1;
        }
        ui->textEditSaida->setText(saida);

    }
    if(j == 0) throw QString("Codigo ID NAO esta cadastrado");
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonRemoverProduto_clicked()//Botao que remove um produto cadastrado
{
    try {
    produto = new Produto;
    QString saida;
    produto->setCodigoid(ui->lineEditCodigoID_2->QLineEdit::text().toInt());
    int j = 0;
    for(int i = 0; i < listaP.getQuantidade(); i++)
    {
        if(produto->getCodigoid() == static_cast<Produto*>(listaP[i])->getCodigoid())
        {
            saida += "Codigo ID removido: \n";
            saida += "ID: " + QString::number(static_cast<Produto*>(listaP[i])->getCodigoid()) + " | ";
            saida += "Preco: " + QString::number(static_cast<Produto*>(listaP[i])->getPreco()) + " | ";
            saida += "Descricao: " + static_cast<Produto*>(listaP[i])->getDescricao() + " | ";
            saida += "Quantidade: " + QString::number(static_cast<Produto*>(listaP[i])->getQuant()) + " | ";
            saida += "\n";
            listaP.retirarPosicao(i);
            j = 1;
        }
    }
    if(j == 0) throw QString("Codigo ID NAO encontrado");
    ui->textEditSaida->setText(saida);

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

//---------------------------------------PEDIDO--------------------------------------------------------------------------
//---------------------------------------PEDIDO--------------------------------------------------------------------------
//---------------------------------------PEDIDO--------------------------------------------------------------------------
//---------------------------------------PEDIDO--------------------------------------------------------------------------
//---------------------------------------PEDIDO--------------------------------------------------------------------------
//---------------------------------------PEDIDO--------------------------------------------------------------------------

void MainWindow::on_pushButton_2CadastrarPedido_clicked()//Botao que cadastra pedidos
{
    try {

        pedido = new Pedido;

        QString codigoId = ui->lineEditCodigoID_3->QLineEdit::text();
        pedido->setCodigoIdentificador(codigoId.toInt());

        QString codigoProduto = ui->lineEditCodigoProduto->QLineEdit::text();
        pedido->setNumero(codigoProduto.toInt());

        QString clientePedido = ui->lineEditCodigoDoCliente->QLineEdit::text();
        pedido->setCliente(clientePedido);

        QString statusPedido = ui->lineEditStatus->QLineEdit::text();
        pedido->setStatus(statusPedido);

        QString dataPedido = ui->lineEditData->QLineEdit::text();
        pedido->setData(dataPedido.toInt());

        QString valorTotalPedido = ui->lineEdit_2ValorTotal->QLineEdit::text();
        pedido->setValorTotal(valorTotalPedido.toFloat());

        for (int i = 0; i < listaI.getQuantidade(); i++)
        {
            if(pedido->getCodigoIdentificador() == static_cast<Pedido*>(listaI[i])->getCodigoIdentificador())
            {
                throw QString("Codigo ID ja esta cadastrado");
                return;
            }
        }

        if(codigoId.isEmpty()){throw  QString ("Campo 'Codigo identificador do Pedido' vazio"); return;}
        if(codigoProduto.isEmpty()){throw  QString ("Campo 'Codigo identificador do Produto' vazio"); return;}
        if(clientePedido.isEmpty()){throw  QString ("Campo 'Codigo identificador do Cliente' vazio"); return;}
        if(statusPedido.isEmpty()){throw  QString ("Campo 'Status' vazio"); return;}
        if(dataPedido.isEmpty()){throw  QString ("Campo 'Data' vazio"); return;}
        if(valorTotalPedido.isEmpty()){throw  QString ("Campo 'Valor Total' vazio"); return;}

        listaI.inserirOrdenado(pedido);

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_3ListarPedido_clicked()//Botao que lista os pedidos cadastrados
{
    QString saida;
    for (int i = 0; i < listaI.getQuantidade(); i++)
    {
        saida += "ID do Pedido: " + QString::number(static_cast<Pedido*>(listaI[i])->getCodigoIdentificador()) + " | ";
        saida += "ID do Produto: " + QString::number(static_cast<Pedido*>(listaI[i])->getNumero()) + " | ";
        saida += "ID do Cliente: " + QString(static_cast<Pedido*>(listaI[i])->getCliente()) + " | ";
        saida += "Status: " + QString(static_cast<Pedido*>(listaI[i])->getStatus()) + " | ";
        saida += "Data: " + QString::number(static_cast<Pedido*>(listaI[i])->getData()) + " | ";
        saida += "Valor total: " + QString::number(static_cast<Pedido*>(listaI[i])->getValorTotal()) + "\n";
        saida += "-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    ui->textEditSaidaPedido->setText(saida);
}

void MainWindow::on_pushButtonConsultarPedido_clicked()//Botao que consulta se um pedido esta cadastrado
{
    try {
        pedido = new Pedido;
        QString saida;
        QString codigoId = ui->lineEditCodigoID_3->QLineEdit::text();
        pedido->setCodigoIdentificador(codigoId.toInt());
        int j = 0;
        for (int i = 0; i < listaI.getQuantidade(); i++)
        {
            if(pedido->getCodigoIdentificador() == static_cast<Pedido*>(listaI[i])->getCodigoIdentificador())
            {
                saida += "Codigo ID do pedido esta cadastrado: \n";
                saida += "ID do Pedido: : " + QString::number(static_cast<Pedido*>(listaI[i])->getCodigoIdentificador()) + " | ";
                saida += "ID do Produto: " + QString::number(static_cast<Pedido*>(listaI[i])->getNumero()) + " | ";
                saida += "ID do Cliente: " + QString(static_cast<Pedido*>(listaI[i])->getCliente()) + " | ";
                saida += "Status: " + QString(static_cast<Pedido*>(listaI[i])->getStatus()) + " | ";
                saida += "Data: " + QString::number(static_cast<Pedido*>(listaI[i])->getData()) + " | ";
                saida += "Valor total: " + QString::number(static_cast<Pedido*>(listaI[i])->getValorTotal()) + "\n";
                j = 1;
            }
        }
        if (j == 0) throw  QString("Codigo ID DO PEDIDO nao cadastrado");
        ui->textEditSaidaPedido->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO",erro);

    }

}

void MainWindow::on_pushButton_2RemoverPedido_clicked()//Botao que remove um pedido cadastrado
{
    try {
        pedido = new Pedido;
        QString saida;
        QString codigoId = ui->lineEditCodigoID_3->QLineEdit::text();
        pedido->setCodigoIdentificador(codigoId.toInt());
        int j = 0;
        for (int i = 0; i < listaI.getQuantidade(); i++)
        {
            if(pedido->getCodigoIdentificador() == static_cast<Pedido*>(listaI[i])->getCodigoIdentificador())
            {
                saida += "Pedido Removido: \n";
                saida += "ID do Pedido: " + QString::number(static_cast<Pedido*>(listaI[i])->getCodigoIdentificador()) + " | ";
                saida += "ID do Produto: " + QString::number(static_cast<Pedido*>(listaI[i])->getNumero()) + " | ";
                saida += "ID do Cliente: " + QString(static_cast<Pedido*>(listaI[i])->getCliente()) + " | ";
                saida += "Status: " + QString(static_cast<Pedido*>(listaI[i])->getStatus()) + " | ";
                saida += "Data: " + QString::number(static_cast<Pedido*>(listaI[i])->getData()) + " | ";
                saida += "Valor total: " + QString::number(static_cast<Pedido*>(listaI[i])->getValorTotal()) + "\n";
                listaI.retirarPosicao(i);
                j = 1;
            }
        }
        if (j == 0) throw  QString("Codigo ID DO PEDIDO nao encontrado");
        ui->textEditSaidaPedido->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO",erro);

    }

}
