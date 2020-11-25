package exercises.list05;

import java.util.ArrayList;
import java.util.List;

public class Consultor extends Funcionario{

    List<Funcionario> subordinados = new ArrayList<>();

    public Consultor(String cpf, String nome, Integer idade, boolean sexo, Double valorVendido, Consultor patrao) {
        super(cpf, nome, idade, sexo, valorVendido);
    }

    @Override
    public double calculaComissao() {

        double comissaoSubordinados = 0;

        for (Funcionario subordinado : subordinados) {
            comissaoSubordinados += subordinado.calculaComissao() * 0.3;
        }

        return getValorVendido()*0.15 + comissaoSubordinados;
    }

    public void addSubordinado(Funcionario f) {
        if (subordinados.contains(f)){
            return;
        }

        subordinados.add(f);
    }

    public void rmSubordinado(Funcionario f) {
        if (!subordinados.contains(f)) {
            return;
        }

        subordinados.remove(f);
    }

    public int numSubordinados() {
        return subordinados.size();
    }
}
