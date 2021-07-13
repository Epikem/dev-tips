var count = {};
function counter(arr) {
    arr.forEach((val)=>{
        val = val.split('');
        val = val.sort();
        val = val.join('');
        count[val] = (count[val] || 0) + 1;
    });
    return count;
}

var results = [];
function ranges(from, to, cur,order) {
    if(from===to){
        return;
    }
    results.push(cur);
    for(var i=from+1;i<=to;i++){
        ranges(i,to,cur+order[i] || '',order);
    }
}

var max_courses = {};
var len_to_maxcnts = {};
// var val_to_courses = {};
function getMaxCourses(counts) {
    for (var [key, val] of Object.entries(counts)) {
        var len = key.length;
        var cnt = val;
        
        if (len_to_maxcnts[len] === cnt) {
            max_courses[len].push(key);
        } else if(len_to_maxcnts[len] < cnt || !len_to_maxcnts[len] && cnt>=2) {
            len_to_maxcnts[len] = cnt;
            max_courses[len] = [key];
        }
    }
}

function solution(orders, course) {
    var picks = {};
    var answer = [];
    for (var order of orders) {
        results = [];
        ranges(-1,order.length,'',order);
        //console.log(results);
        counter(results);
        //console.log(res);
    }
    
    // console.log(count);
    
    var courses=[];
    for (var i=0;i<course.length;i++){
        courses[course[i]] = 1;
    }
    
    getMaxCourses(count);
    
    // console.log(max_courses);
    // console.log(len_to_maxcnts);
    for (var [key, val] of Object.entries(max_courses)) {
        // console.log(key,val);
        if (courses[key] && key >= 2) {
            // answer.concat(val);
            for(var item of val) {
                //console.log(item);
                answer.push(item);
            }
        }
    }
    
    answer.sort();
    
    return answer;
}