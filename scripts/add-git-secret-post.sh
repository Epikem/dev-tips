# add new post to git secret and hides
# eg. TIL/2022-01-01.md
git secret add $(pwd)/TIL/$1.md;
# hide the post
git secret hide -dmF;
# add the post to git
git add .gitsecret/paths/mapping.cfg $(pwd)/TIL/$1.md.secret;
# add TODO
git add $(pwd)/TODO;
# commit and push?
push=$2;
# set default
if [ -z "$push" ]; then
    push="no-push";
    echo "no-push";
fi

if [ $push = "push" ]; then
    echo "push";
    git commit -m "add $1";
    git push;
fi
