import java.text.CollationElementIterator;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

public class Perfomence {
    static int numElements = 100000;
    static int numTests = 100;

    //creating a 2-D list of lists structure with arrayList
    static ArrayList<ArrayList<Float>> timeList = new ArrayList<>();

    // Instantiate collections
    static HashSet<Integer> hashSet = new HashSet<>();
    static TreeSet<Integer> treeSet = new TreeSet<>();
    static LinkedHashSet<Integer> linkedHashSet = new LinkedHashSet<>();
    static ArrayList<Integer> arrayList = new ArrayList<>();
    static LinkedList<Integer> linkedList = new LinkedList<>();
    static ArrayDeque<Integer> arrayDeque = new ArrayDeque<>();
    static PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
    static HashMap<Integer, Integer> hashMap = new HashMap<>();
    static TreeMap<Integer, Integer> treeMap = new TreeMap<>();
    static LinkedHashMap<Integer, Integer> linkedHashMap = new LinkedHashMap<>();
    static ArrayList<Collection<Integer>> collectionArrayList = new ArrayList<>();
    static ArrayList<Map<Integer, Integer>> mapArrayList = new ArrayList<>();
    public static void main(String[] args){
        // Load all the collections and maps
        load();
        long start, end;
        float cummulativeTime = 0;
        for (Collection<Integer> collection: collectionArrayList){
            // Initialize a backup collection
            Collection<Integer> collectionBackup = collection;
            // Initializing a list to store times of curretn collection
            ArrayList<Float> innerList = new ArrayList<>();

            // Run 100 add operation for collection and get the average time
            for (int i=0; i<numTests; i++) {
                start  = System.nanoTime();
                addElementToCollections(collection);
                end = System.nanoTime();
                cummulativeTime += end - start;
                collection = collectionBackup;
            }
            innerList.add(cummulativeTime/100);

            // Run 100 remove operation for collection and get the average time
            cummulativeTime = 0;
            for (int i=0; i<numTests; i++) {
                start  = System.nanoTime();
                removeElementFromCollection(collection);
                end = System.nanoTime();
                cummulativeTime += end - start;
                collection = collectionBackup;
            }
            innerList.add(cummulativeTime/100);
            cummulativeTime = 0;

            // Run 100 contains operation for collection and get the average time
            for (int i=0; i<numTests; i++) {
                start  = System.nanoTime();
                containsInTheCollection(collection);
                end = System.nanoTime();
                cummulativeTime += end - start;
                collection = collectionBackup;
            }
            innerList.add(cummulativeTime/100);
            cummulativeTime = 0;

            // Run 100 clear operation for collection and get the average time
            for (int i=0; i<numTests; i++) {
                start  = System.nanoTime();
                collection.clear();
                end = System.nanoTime();
                cummulativeTime += end - start;
                collection = collectionBackup;
            }
            innerList.add(cummulativeTime/100);
            System.out.println(innerList);
            timeList.add(innerList);
        }
        for (Map<Integer, Integer> map: mapArrayList){
            // Initialize a backup map
            Map<Integer, Integer> mapBackup = map;
            // Initializing a list to store times of curretn collection
            ArrayList<Float> innerList = new ArrayList<>();

            // Run 100 add operation for map and get the average time
            for (int i=0; i<numTests; i++) {
                start  = System.nanoTime();
                putElementToMap(map);
                end = System.nanoTime();
                cummulativeTime += end - start;
                map = mapBackup;
            }
            innerList.add(cummulativeTime/100);
            cummulativeTime = 0;

            // Run 100 remove operation for map and get the average time
            for (int i=0; i<numTests; i++) {
                start  = System.nanoTime();
                removeElementFromMap(map);
                end = System.nanoTime();
                cummulativeTime += end - start;
                map = mapBackup;
            }
            innerList.add(cummulativeTime/100);
            cummulativeTime = 0;

            // Run 100 contain operation for map and get the average time
            for (int i=0; i<numTests; i++) {
                start  = System.nanoTime();
                containsInTheMap(map);
                end = System.nanoTime();
                cummulativeTime += end - start;
                map = mapBackup;
            }
            innerList.add(cummulativeTime/100);
            cummulativeTime = 0;

            // Run 100 clear operation for map and get the average time
            for (int i=0; i<numTests; i++) {
                start  = System.nanoTime();
                map.clear();
                end = System.nanoTime();
                cummulativeTime += end - start;
                map = mapBackup;
            }
            innerList.add(cummulativeTime/100);
            System.out.println(innerList);
            timeList.add(innerList);
        }
    }
    public static void load(){
        // Fill collections with random integers
        while (hashSet.size() < numElements) {
            int randInt = ThreadLocalRandom.current().nextInt(0, 100000);
            if (hashSet.contains(randInt)) {
                continue;
            }
            hashSet.add(randInt);
            treeSet.add(randInt);
            linkedHashSet.add(randInt);
            arrayList.add(randInt);
            linkedList.add(randInt);
            arrayDeque.add(randInt);
            priorityQueue.add(randInt);
            hashMap.put(randInt, randInt);
            treeMap.put(randInt, randInt);
            linkedHashMap.put(randInt, randInt);
        }
        // Add collections and maos to particular list
        collectionArrayList.add(hashSet);
        collectionArrayList.add(treeSet);
        collectionArrayList.add(linkedHashSet);
        collectionArrayList.add(arrayList);
        collectionArrayList.add(linkedList);
        collectionArrayList.add(arrayDeque);
        collectionArrayList.add(priorityQueue);
        mapArrayList.add(hashMap);
        mapArrayList.add(treeMap);
        mapArrayList.add(linkedHashMap);
    }
    // Adding a element to the collection
    public static void addElementToCollections(Collection<Integer> collection){
        int randInt = ThreadLocalRandom.current().nextInt(0, 100000);
        collection.add(randInt);
    }
    // Remove a element from the collection
    public static void removeElementFromCollection(Collection<Integer> collection){
        int randInt = ThreadLocalRandom.current().nextInt(0,100000);
        collection.remove(randInt);
    }
    // Run contains for the collection
    public static void containsInTheCollection(Collection<Integer> collection){
        int randInt = ThreadLocalRandom.current().nextInt(0,100000);
        collection.contains(randInt);
    }
    // Put element to the map
    public static void putElementToMap(Map<Integer, Integer> map){
        int randInt = ThreadLocalRandom.current().nextInt(0, 100000);
        map.put(randInt,randInt);
    }
    // remove an element from the map
    public static void removeElementFromMap(Map<Integer, Integer> map){
        int randInt = ThreadLocalRandom.current().nextInt(0, 100000);
        map.remove(randInt);
    }
    // Run contains key
    public static void containsInTheMap(Map<Integer, Integer> map){
        int randInt = ThreadLocalRandom.current().nextInt(0, 100000);
        map.containsKey(randInt);
    }
}