package poo_java_05_class_ex_pratico;

public class UserAccount {
    private String email;
    private String userName;

    private Post[] timeline = new Post[10];
    private Post[] myPosts = new Post[1000];
    private UserAccount[] followers = new UserAccount[1000];

    private int countMyPosts, countTimeline, countFollowers = 0;

    public UserAccount(String email, String userName) {
        this.email = email;
        this.userName = userName;
    }

    public boolean deletePost(int postIdx){
        if(postIdx >= 0 && postIdx < countMyPosts) {
            myPosts[postIdx] = null;
            return true;
        }
        return false;
    }

    public String showTimeline(){
        StringBuilder sb = new StringBuilder();
        for (Post post : timeline) {
            if(post != null) {
                String postContent = post.show();
                sb.append(postContent);
            }
        }
        return sb.toString();
    }

    public String showMyPost(){
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < countMyPosts; i++) {
            Post post = myPosts[i];
            if(post != null) {
                String postContent = post.show();
                sb.append(postContent);
            }
        }
        return sb.toString();
    }

    public String showMyFollowers(){
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < countFollowers; i++) {
            UserAccount follower = followers[i];
            if(follower != null) {
                sb.append("Name: " + follower.getUserName() + " Email: " + follower.getEmail());
            }
        }
        return sb.toString();
    }

    public void clapPost(int postIndex){
        if(postIndex >= 0 && postIndex < 10){
            Post post = timeline[postIndex];
            post.clap();
        }
    }

    public void booPost(int postIndex){
        if(postIndex >= 0 && postIndex < 10){
            Post post = timeline[postIndex];
            post.boo();
        }
    }

    public void publish(String quote){
        if (quote != null && !quote.isEmpty()){
            Post newPost = publishAndPutInMyPosts(quote);
            requestFollowersToUpdateTimeLine(newPost);
        }
    }

    private void requestFollowersToUpdateTimeLine(Post newPost) {
        for (int i = 0; i < countFollowers; i++) {
            UserAccount follower = followers[i];
            follower.updateTimeline(newPost);
        }
    }

    private Post publishAndPutInMyPosts(String quote) {
        Post newPost = new Post(quote,this );
        myPosts[countMyPosts] = newPost;
        countMyPosts++;
        return newPost;
    }

    public void updateTimeline(Post newPost) {
        timeline[countTimeline % 10] = newPost;
        countTimeline++;
    }

    public void acceptFollower(UserAccount newFollower) {
        followers[countFollowers] = newFollower;
        countFollowers++;
    }
    
    public void blockFollower(UserAccount follower){
        for (int i = 0; i < countFollowers; i++) {
            UserAccount f = followers[i];
            if (f != null && f.equals(follower)) {
                followers[i] = null;
                break;
            }
        }
    }

    public String getEmail() {
        return email;
    }

    public String getUserName() {
        return userName;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }
}
