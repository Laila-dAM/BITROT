import { openDialogue } from "./dialogue.js"
import { state } from "./state.js"

const npcs = {
  professor: {
    x: 10,
    y: 6
  }
}

export function getNPCAt(x, y) {
  return Object.values(npcs).find(n => n.x === x && n.y === y)
}

export function interactWithNPC(npc) {
  if (!npc) return

  let path = "assets/ascii/dialogues/professor_xp_low.json"

  if (state.xp >= 50) {
    path = "assets/ascii/dialogues/professor_xp_mid.json"
  }

  if (state.xp >= 100) {
    path = "assets/ascii/dialogues/professor_xp_high.json"
  }

  if (state.flags.chose_escape) {
    path = "assets/ascii/dialogues/professor_escape.json"
  }

  if (state.flags.chose_learn && state.xp >= 100) {
    path = "assets/ascii/dialogues/professor_learning.json"
  }

  openDialogue(path)
}
