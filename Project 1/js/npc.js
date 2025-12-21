import { openDialogue } from "./dialogue.js"
import { state } from "./state.js"

const npcs = {
  professor: {
    x: 10,
    y: 6,
    type: "professor"
  },
  survivor: {
    x: 5,
    y: 8,
    dialogue: "assets/ascii/dialogues/survivor.json"
  },
  technician: {
    x: 15,
    y: 10,
    dialogue: "assets/ascii/dialogues/technician.json"
  },
  child: {
    x: 18,
    y: 4,
    dialogue: "assets/ascii/dialogues/child.json"
  }
}

export function getNPCAt(x, y) {
  return Object.values(npcs).find(n => n.x === x && n.y === y)
}

export function interactWithNPC(npc) {
  if (!npc) return

  if (npc.type === "professor") {
    let path = "assets/ascii/dialogues/professor_xp_low.json"

    if (state.xp >= 50) path = "assets/ascii/dialogues/professor_xp_mid.json"
    if (state.xp >= 100) path = "assets/ascii/dialogues/professor_xp_high.json"
    if (state.flags.chose_escape) path = "assets/ascii/dialogues/professor_escape.json"
    if (state.flags.chose_learn && state.xp >= 100)
      path = "assets/ascii/dialogues/professor_learning.json"

    openDialogue(path)
    return
  }

  openDialogue(npc.dialogue)
}
