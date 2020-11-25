package exercises.list05;

public class Revendedor extends Funcionario {

    public Revendedor(String cpf, String nome, Integer idade, boolean sexo, Double valorVendido, Consultor patrao) {
        super(cpf, nome, idade, sexo, valorVendido);
        if(patrao != null) {
            patrao.addSubordinado(this);
        }
    }

    @Override
    public double calculaComissao() {
        return getValorVendido()*0.15;
    }

}
