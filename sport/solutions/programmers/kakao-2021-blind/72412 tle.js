// const lang = ['cpp','java','python','-'];
// const type = ['backend','frontend','-'];
// const exp = ['junior', 'senior', '-'];
// const food = ['chicken','pizza','-'];
const db = {};

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
                            db[r] = [score];
                        } else {
                            db[r].push(score);
                        }
                    }
                }
            }
        }
    })
}

function solution(info, query) {
    saveInfoes(info);
    
    var answer = [];
    // console.log('CALC');
    for (var q of query) {
        var spaceIdx = q.lastIndexOf(' ');
        var hash = q.slice(0,spaceIdx);
        var score = q.slice(spaceIdx+1) - 0;
        var cnt=0;
        
        // console.log(hash, score, db[hash]);
        (db[hash] || []).forEach(s=>{
            if(s>=score){
                cnt+=1;
            }
        })
        answer.push(cnt);
    }
    
    return answer;
}