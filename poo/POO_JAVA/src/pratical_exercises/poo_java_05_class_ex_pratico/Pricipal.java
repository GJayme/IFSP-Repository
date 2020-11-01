package poo_java_05_class_ex_pratico;

public class Pricipal {
    public static void main(String[] args) {
        UserAccount user1 = new UserAccount("user1@email.com", "User1 da Silva");
        UserAccount user2 = new UserAccount("user2@email.com", "User2 da Silva");
        UserAccount user3 = new UserAccount("user3@email.com", "User3 da Silva");
        UserAccount user4 = new UserAccount("user4@email.com", "User4 da Silva");
        UserAccount user5 = new UserAccount("user5@email.com", "User5 da Silva");
        UserAccount user6 = new UserAccount("user6@email.com", "User6 da Silva");
        UserAccount user7 = new UserAccount("user7@email.com", "User7 da Silva");

        user1.acceptFollower(user2);
        user1.acceptFollower(user3);
        user1.acceptFollower(user4);
        user1.acceptFollower(user5);
        user1.acceptFollower(user6);
        user1.acceptFollower(user7);

        user1.publish("Palmeiras não tem mundial!");
        String myPosts = user1.showMyPost();
        System.out.println(myPosts);

        user3.publish("Corinthians também não tem!!");
        System.out.println(myPosts);

        System.out.println("User 2 - Timeline");
        String timeLine = user2.showTimeline();
        System.out.println(timeLine);
    }
}
