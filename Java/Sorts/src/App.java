public class App {
    private final static int TAM_ARRAY = 5;
    private final static int QTD_ARRAYS = 15;
    public static void main(String[] args) throws Exception {
        SortArrayService<Double> service = new SortArrayService<>();
        Double array[][] = new Double[QTD_ARRAYS][TAM_ARRAY];

        System.out.println("SELECTION SORT:\n\n");
        service.generateRandomArray(array[0], TAM_ARRAY, (rand) -> (rand.nextDouble() * (rand.nextDouble() + 10)) - 0.5);
        System.out.println("--- ANTES ---");
        service.printArray(array[0]);

        service.selection_sort(array[0], TAM_ARRAY, (n1, n2) -> n1 > n2);
        System.out.println("--- DEPOIS ---");
        service.printArray(array[0]);

        System.out.println("INSERTION SORT:\n\n");

        service.generateRandomArray(array[1], TAM_ARRAY, (rand) -> (rand.nextDouble() * (rand.nextDouble() + 40)) - 0.5);
        System.out.println("--- ANTES ---");
        service.printArray(array[1]);

        service.insertion_sort(array[1], TAM_ARRAY, (n1, n2) -> n1 < n2, 1);

        System.out.println("--- DEPOIS ---");
        service.printArray(array[1]);

        System.out.println("BUBBLE SORT:\n\n");
        Student studentArray[] = new Student[TAM_ARRAY];
        SortArrayService<Student> serviceStudent = new SortArrayService<>();

        serviceStudent.generateRandomArray(studentArray, TAM_ARRAY, (random) -> new Student("TESTE", random.nextInt(), (random.nextDouble() + 600)*1.5));

        System.out.println("--- ANTES ---");
        serviceStudent.printArray(studentArray);

        System.out.println("--- DEPOIS ---");
        serviceStudent.bubble_sort(studentArray, TAM_ARRAY, (n1, n2) -> (n1.compareTo(n2)) > 0);
        serviceStudent.printArray(studentArray);

        System.out.println("MERGE SORT:\n\n");
        service.generateRandomArray(array[2], TAM_ARRAY, (rand) -> (rand.nextDouble() * (rand.nextDouble() + 10)) - 0.5);
        System.out.println("--- ANTES ---");
        service.printArray(array[2]);

        System.out.println("--- DEPOIS ---\n");
        service.merge_sort(array[2], 0, TAM_ARRAY - 1, (n1, n2) -> n1 > n2);
        service.printArray(array[2]);

        System.out.println("SHEL SORT:\n\n");
        service.generateRandomArray(array[3], TAM_ARRAY, (rand) -> (rand.nextDouble() * (rand.nextDouble() + 10)) - 0.5);
        System.out.println("--- ANTES ---");
        service.printArray(array[3]);
        
        System.out.println("--- DEPOIS ---\n");
        service.shell_sort(array[3], TAM_ARRAY, (n1, n2) -> n1 > n2);
        service.printArray(array[3]);



        // System.out.println("--- ARRAY[2] ---");
        // service.generateRandomArray(array[2], TAM_ARRAY, (rand) -> (rand.nextDouble() * (rand.nextDouble() + 10)) - 0.5);
        // service.insertion_sort(array[2], TAM_ARRAY, (n1, n2) -> n1 < n2);
        // service.printArray(array[2]);

        // System.out.println("--- ARRAY[3] ---");
        // service.generateRandomArray(array[3], TAM_ARRAY, (rand) -> (rand.nextDouble() * (rand.nextDouble() + 10)) - 0.5);
        // service.insertion_sort(array[3], TAM_ARRAY, (n1, n2) -> n1 > n2);
        // service.printArray(array[3]);

        // Double mergedArray[] = new Double[TAM_ARRAY*2];

        // System.out.println("--- MERGED ARRAY ---");
        // service.mergeArrays(array[2], array[3], TAM_ARRAY, TAM_ARRAY, mergedArray);
        // service.printArray(mergedArray);

        // System.out.println("--- INTERCALATED ARRAY ---");
        // service.intercalateArrays(mergedArray, 0, TAM_ARRAY - 1, TAM_ARRAY, TAM_ARRAY*2 - 1, (n1, n2) -> n1 < n2);
        // service.printArray(mergedArray);
    }
}
