package exercises.list05;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.Function;

public class FuncionarioDAO implements GenericDAO<Funcionario, String>{

    Map<String, Funcionario> dbFuncionario = new HashMap<>();

    @Override
    public boolean insert(Funcionario object) {
        if(dbFuncionario.containsKey(object.getCpf())) {
            return false;
        }

        dbFuncionario.put(object.getCpf(), object);
        return true;
    }

    @Override
    public Funcionario findOne(String key) {
        if(!dbFuncionario.containsKey(key)) {
            return null;
        }

        return dbFuncionario.get(key);
    }

    @Override
    public List<Funcionario> findAll() {
        List<Funcionario> allFuncionarios = new ArrayList<>();

        for (Map.Entry<String, Funcionario> entry : dbFuncionario.entrySet()) {
            allFuncionarios.add(entry.getValue());
        }

        return allFuncionarios;
    }

    @Override
    public boolean update(Funcionario object) {
        if (!dbFuncionario.containsKey(object.getCpf())) {
            return false;
        }

        dbFuncionario.replace(object.getCpf(), object);
        return true;
    }

    @Override
    public boolean remove(String key) {
        if (!dbFuncionario.containsKey(key)) {
            return false;
        }

        dbFuncionario.remove(key);
        return true;
    }
}
