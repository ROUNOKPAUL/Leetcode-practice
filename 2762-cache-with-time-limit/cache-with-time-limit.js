class TimeLimitedCache{
    constructor(){
        //constructor function
        this.cache=new Map();
    }
    //Methods defined inside the class 
    set(key, value,duration){
        //Method implementation
        const alreadyExists=this.cache.get(key);
        if(alreadyExists){
            clearTimeout(alreadyExists.timeoutId);
        }
        const timeoutId=setTimeout(()=>{
            this.cache.delete(key)
        },duration)
        this.cache.set(key,{value,timeoutId})
        return Boolean(alreadyExists)
    }
    get(key){
        //Method implementation
        if(this.cache.has(key)){
            return this.cache.get(key).value;
        }
        return -1;
    }
    count(){
        //Method implementation
        return this.cache.size; 
    }
}