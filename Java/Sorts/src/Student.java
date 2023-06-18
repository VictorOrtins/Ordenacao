import java.util.Objects;

public class Student implements Comparable<Student>{
    private String name;
    private Integer id;
    private Double enemScore;

    public Student() {
    }

    public Student(String name, Integer id, Double enemScore) {
        this.name = name;
        this.id = id;
        this.enemScore = enemScore;
    }

    @Override
    public boolean equals(Object o) {
        if (o == this)
            return true;
        if (!(o instanceof Student)) {
            return false;
        }
        Student student = (Student) o;
        return Objects.equals(name, student.name) && Objects.equals(id, student.id) && Objects.equals(enemScore, student.enemScore);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, id, enemScore);
    }

    @Override
    public String toString() {
        return "{" +
            " name = " + getName() + " " +
            ", id = " + getId() + " " +
            ", enemScore = " + getEnemScore() + " " +
            "}";
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getId() {
        return this.id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Double getEnemScore() {
        return this.enemScore;
    }

    public void setEnemScore(Double enemScore) {
        this.enemScore = enemScore;
    }

    @Override
    public int compareTo(Student o) {
        return this.getEnemScore().compareTo(o.getEnemScore());
    }

}
