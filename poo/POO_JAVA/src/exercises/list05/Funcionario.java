package exercises.list05;

import java.util.Objects;

public abstract class Funcionario {

    private String cpf;
    private String nome;
    private Integer idade;
    private boolean sexo;
    private Double valorVendido;

    public abstract double calculaComissao();

    public Funcionario(String cpf, String nome, Integer idade, boolean sexo, Double valorVendido) {
        this.cpf = cpf;
        this.nome = nome;
        this.idade = idade;
        this.sexo = sexo;
        this.valorVendido = valorVendido;
    }

    @Override
    public String toString() {
        return "Funcionario: " + nome
                + " CPF: " + cpf
                + " Idade: " + idade
                + " Sexo: " + sexo
                + " valor vendido: " + valorVendido;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Funcionario that = (Funcionario) o;
        return cpf.equals(that.cpf);
    }

    @Override
    public int hashCode() {
        return Objects.hash(cpf);
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Integer getIdade() {
        return idade;
    }

    public void setIdade(Integer idade) {
        this.idade = idade;
    }

    public boolean isSexo() {
        return sexo;
    }

    public void setSexo(boolean sexo) {
        this.sexo = sexo;
    }

    public Double getValorVendido() {
        return valorVendido;
    }

    public void setValorVendido(Double valorVendido) {
        this.valorVendido = valorVendido;
    }
}
