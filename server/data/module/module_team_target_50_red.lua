module:setBounce(1);
module:setScore(50);
module:setAccel(0.0001);
module:setFriction(5.0);
module:setShapeName("team_target_50_red.shape");

module:setUserData(CModule:new(module,0)); --new CModule , init team to 0
