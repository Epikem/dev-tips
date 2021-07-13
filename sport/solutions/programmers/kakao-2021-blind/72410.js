function solution(new_id) {
    var answer = new_id;
    // 1
    answer = answer.toLowerCase();
    // 2
    answer = answer.replace(/[^a-z0-9\-_\.]/g, '');
    // 3
    let before_dot = false;
    let next_answer = [];
    for (let i=0;i<answer.length;i++){
        
        if (answer[i] == '.') {
            if (before_dot) {
                continue;
            }
            before_dot = true;
        } else {
            before_dot = false;
        }
        
        next_answer.push(answer[i]);
    }
    
    answer = next_answer;
    // 4
    if (answer[0] == '.') {
        answer.shift();
    }
    if (answer[answer.length - 1] == '.') {
        answer.pop();
    }
    
    // 5
    if (answer.length == 0) {
        answer.push('a');
    }
    
    // 6
    answer = answer.slice(0,15);
    if (answer[answer.length - 1] == '.') {
        answer.pop();
    }
    
    // 7
    let last_char = answer[answer.length - 1];
    while (answer.length <= 2) {
        answer.push(last_char);
    }
    answer = answer.join('');
    console.log(answer);
    return answer;
}