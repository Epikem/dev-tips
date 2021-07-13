// const lang = ['cpp','java','python','-'];
// const type = ['backend','frontend','-'];
// const exp = ['junior', 'senior', '-'];
// const food = ['chicken','pizza','-'];
const db = {};
const hashes = {};

function saveInfoes(infoes) {
    infoes.forEach(info => {
        const [lang,type,exp,food,score] = info.split(' ');
        // console.log(lang,type,exp,food,score);
        
        const langs = [lang, '-'];
        const types = [type, '-'];
        const exps = [exp, '-'];
        const foods = [food, '-'];
        
        for(var lan of langs) {
            for(var typ of types) {
                for (var ex of exps) {
                    for (var foo of foods) {
                        var r = [lan,typ,ex,foo].join(' and ');
                        // console.log(r);
                        if(!db[r]) {
                            db[r] = [score - 0];
                        } else {
                            db[r].push(score - 0);
                        }
                        hashes[r] = false;
                    }
                }
            }
        }
    })
}

function solution(info, query) {
    saveInfoes(info);
    
    for (var [key,val] of Object.entries(hashes)) {
        db[key].sort((a,b)=>{
            return a-b;
        });
    }
    
    // console.log(hashes);
    
    var answer = [];
    // console.log('CALC');
    for (var q of query) {
        var spaceIdx = q.lastIndexOf(' ');
        var hash = q.slice(0,spaceIdx);
        var score = q.slice(spaceIdx+1) - 0;
        //var qs = q.split(' ');
        //var score = qs.pop() - 0;
        //var hash = qs.join(' ');
        var cnt=0;
        
        var left = 0;
        var items = db[hash] || [];
        var itemlen = items.length;
        var right = itemlen;
        var mid;
        var val;
        // console.log('left',left,'right',right);
        while(left<right) {
            mid = Math.floor((left+right)/2);
            val = items[mid];
            // console.log('mid',mid,'val',val, 'score',score);
            // score보다 큰 최초의 값 위치를 찾아야 한다.
            if(val<score) {
                // 
                left=mid+1;
            } else {
                right=mid;
            }
        }
        // console.log(items, left, mid, right);
        answer.push(itemlen - right);
    }
    
    return answer;
}